/*
84. Largest Rectangle in Histogram
Hard

5479

111

Add to List

Share
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max = 0;
        int n = heights.size();
        
        // firstSmallLeft[i] = p stores the index of the first number to the left of i
        // where heights[p] < heights[i]
        // sim for firstSmallRight
        // so that area at i is heigts[i] * (r -l -1)
        
        vector<int> firstSmallLeft(n); 
        for(int i=0;i<n;++i){
            int p = i-1;
            while(p>=0 && heights[p] >= heights[i]){
                p = firstSmallLeft[p];
            }
            firstSmallLeft[i] = p;
        }

        vector<int> firstSmallRight(n);
        for(int i=n-1;i>-1;--i){
            int p = i+1;
            while(p<n && heights[p] >= heights[i]){
                p = firstSmallRight[p];
            }
            firstSmallRight[i] = p;
        }
        
        for(int i=0;i<n;++i){
            int area = heights[i] * (firstSmallRight[i] - firstSmallLeft[i] - 1);
            if(area > max){
                max = area;
            }
        }
        return max;
    }
};
