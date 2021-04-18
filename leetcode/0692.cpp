/*
692. Top K Frequent Words

Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
*/


class Compare{
public:
    bool operator() (pair<int,string> p1, pair<int,string> p2){
        if(p1.first != p2.first){
            return p1.first > p2.first;
        }else{
            return p1.second.compare(p2.second) < 0;
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> count;
        for(int i=0;i<words.size();++i){
            count[words[i]]++;
        }
        
        priority_queue<pair<int,string>,vector<pair<int,string>>, Compare> pq; // min-heap
        for(auto it=count.begin();it!=count.end();++it){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<string> ret;
        while(k--){
            ret.push_back(pq.top().second);
            cout << pq.top().second << pq.top().first << '\n';
            pq.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
