/*
703. Kth Largest Element in a Stream

Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Returns the element representing the kth largest element in the stream.

*/

class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int> > q;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i =0;i<nums.size(); ++i){
            int num = nums[i];
            q.push(num);
        }
        while(q.size() > size){
            q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        while(q.size() > size){
            q.pop();
        }        
        return q.top();
    }
};
