/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]


Example 2:

Input: n = 1
Output: ["()"]

Constraints:

1 <= n <= 8
*/

class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        recursion("(",1,n-1, n);
        return ans;
    }
    void recursion( string candidate, int cur, int left, int max){
        if(cur < 0 || cur > max || left < 0){
            return;
        }
        if(left == 0 && cur == 0){
            ans.push_back(candidate);
        }
        recursion(candidate+")", cur-1,left, max);
        recursion(candidate+"(", cur+1,left-1, max);
    }
};

class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        recursion("(",1,n-1, n);
        return ans;
    }
    void recursion( string candidate, int cur, int left, int max){
        if(left == 0 && cur == 0){
            ans.push_back(candidate);
        }
        if(cur > 0){
            recursion(candidate+")", cur-1,left, max);
        }
        if(cur <= max && left > 0){
            recursion(candidate+"(", cur+1,left-1, max);
        }
    }
};
