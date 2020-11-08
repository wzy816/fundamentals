// https://www.hackerrank.com/challenges/deque-stl/problem
#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
    // use deq to store index to which items in descent order
    // for every new item, pop all items from the back
    // if it is smaller than the new item
    // ex. 3 4 6 3 4
    // @3 => push 0
    // @4 => pop 0, push 1 => 4
    // @6 => pop 1, push 2 => 6
    // @3 => do nothing, => 6
    // @4 => pop 2(out of window), push 4, => 4
    deque<int> deq;
    for(int i=0; i< n; i++){

        // pop out all items that are smaller than arr[i]
        while(!deq.empty()){
            int s = deq.size();
            if(arr[deq[s-1]] < arr[i]){
                deq.pop_back();
            }else{
                break;
            }
        }
 
        // remove out-of-window items
        if (!deq.empty() && deq[0] == i-k){
            deq.pop_front();
        }  
             
        // push i to the back if deq is not full
        if(deq.size() < k){
            deq.push_back(i);
        }
        
        // when i is at [k-1,n-1], print the first item
        if(i >= k -1){
            cout << arr[deq[0]] << " ";
        }
    }
    cout << endl;
}

int main(){
  
    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
              cin >> arr[i];
        printKMax(arr, n, k);
        t--;
      }
      return 0;
}

