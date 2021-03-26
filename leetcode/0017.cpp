/*
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
 
Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
public:
    vector<string> ans;
    map<char,string> lettermap = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return ans;
        }
        char letter = digits[0];
        string letterString = lettermap[letter];
        string new_digits = digits.substr(1);
        
        if(ans.size() == 0){
            for(int j=0;j<letterString.length();++j){
                ans.push_back(string(1, letterString[j]));
            }
        }else{
            int max = ans.size();
            for(int i=0;i<max;++i){
                string a = ans[i];
                ans[i] += letterString[0];
                for(int j=1;j<letterString.length();++j){
                    string s = a;
                    s += letterString[j];
                    ans.push_back(s);
                }
            }
        }

        
        return letterCombinations(new_digits);
    }
};
