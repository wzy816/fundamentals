/*
719. Find K-th Smallest Pair Distance

Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:
Input:
nums = [1,3,1]
k = 1

Output: 0 

Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 1
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.

Note:
2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.

*/

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        // find max diff by sorting
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.back() - nums[0];

        // bs for
        while (low < high)
        {
            int diff = (low + high) / 2;
            int total = 0;
            int left = 0;
            // use two pointers to frame a window such that nums[right]-nums[left] < diff
            // sum window sizes
            for (int right = 0; right < nums.size(); right++)
            {
                while ((nums[right] - nums[left]) > diff)
                {
                    left += 1;
                }
                total += (right - left);
            }
            if (total >= k)
            {
                high = diff;
            }
            else
            {
                low = diff + 1;
            }
        }
        return low;
    }
};
