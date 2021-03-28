/*
218. The Skyline Problem

A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

lefti is the x coordinate of the left edge of the ith building.
righti is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]
*/

// https://leetcode.com/problems/the-skyline-problem/discuss/1119275/C%2B%2B-36ms-Two-Priority-Queues
// https://www.youtube.com/watch?v=GSBLe8cKu0s&ab_channel=TusharRoy-CodingMadeSimple

class Solution {
public:

    static bool cmp(const vector<int> &b, const vector<int> &a)
    {
        if(b[0] < a[0]){
            return true; // index asc
        }else if(b[0] > a[0]){
            return false; // index asc
        }else{
          // edge cases
          if(b[2] == 1 && a[2] == 1){
            return  b[1] < a[1]; // both end, shorter first
          }else if(b[2] == 0 and a[2]==0){
            return b[1] > a[1]; // both start, taller first
          }else if(b[2] == 0){
            return true; // one end, one start, start first
          }else{
            return false;
          }           
        }
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> bs;
      
        // reorg input
        for(int i=0;i<buildings.size();++i){
            vector<int> start {buildings[i][0], buildings[i][2], 0};
            vector<int> end {buildings[i][1], buildings[i][2], 1};
            bs.push_back(start);
            bs.push_back(end);
        }
        // sort with 
        sort(bs.begin(), bs.end(), cmp);
        
        
        vector<vector<int>> ans;
        // store heights till index
        priority_queue<int> heights;
        heights.push(0);
      
        // ideally use max heap for heights 
        // since priority_queue does not support directly remove ele
        // use another priority_queue to store ele to remove
        priority_queue<int> removed;
        int last_height = 0;
      
        for(int i=0;i<bs.size();++i){
            
            int index = bs[i][0];
            int h = bs[i][1];
            int start_end = bs[i][2];
            
            if(start_end == 0){
                heights.push(h);
            }else{
                removed.push(h);
            }
          
            // skip height that are in removed
            while(removed.size() > 0 && heights.top() == removed.top()){
              heights.pop();
              removed.pop();
            }
            if(heights.top() != last_height){
                ans.push_back({index, heights.top()});
                last_height = heights.top();
            }
        
        }
        return ans;
    }
};
