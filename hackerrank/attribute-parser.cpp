#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<string,string> m;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int N,Q;
    cin >> N >> Q;
    cin.ignore();

    string prefix = "" ;

    // scan input
    for(int i=0; i<N; i++){

        // get line
    string line;
        getline(cin,line);

        if(line[1] == '/'){ // end tag
            int i = 2; // tag start
            while(line[i] != '>') i++; // go to tag end
            
            if((i-2) == prefix.size()){
                prefix = "";
            }else {
                prefix = prefix.substr(0, prefix.size()-(i-2)-1);// rm .tag from prefix
            }
            // cout << "after remove " << prefix.size()-(i-2)-1 << " " << prefix << endl;

        }else{ // start tag
            int i = 1;
            while(line[i] != ' ' && line[i] != '>') i++; 
            string t = line.substr(1,i-1); // tag
            
            // add tag to prefix
            if(prefix.size() == 0){
                prefix= prefix + t;
            }else{
                prefix = prefix + "." + t;
            }
            // cout << "prefix " << prefix << "\n" ;

            while(line[i] != '>'){
                while(line[i] == ' ') i++; // att start
                int j = i;
                while(line[i] != ' ' && line[i] != '=') i++; // att end 
                string k = line.substr(j,i-j);
                // cout << "key " << k << "\n" ;
                
                 while(line[i] == ' ' || line[i] == '='
                 || line[i] == '"') i++;  // value start
                j = i;
                while(line[i] != '"') i++;  // value end
                string v = line.substr(j,i-j);
                // cout << "value " << v << "\n" ;
                m[prefix+"~"+k] = v;
                i++; // pass ""
            }
        
        }

    }
    
    // cout << "output:" << "\n";
    
    // output
    for(int j=0; j<Q; j++){
        string k;
        cin >> k;
        if (m.count(k) == 1){
            cout << m[k] << "\n" ;
        }else{
            cout << "Not Found!\n" ;
        }
    }
    return 0;
}



