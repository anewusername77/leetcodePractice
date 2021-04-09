#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
    public:

        vector<string> letterCombinations(string digits){
            if(digits.empty()) return {};

            unordered_map<char, string> dict{{'2', "abc"},
                                             {'3', "def"},
                                             {'4', "ghi"},
                                             {'5', "jkl"},
                                             {'6', "mno"},
                                             {'7', "pqrs"},
                                             {'8', "tuv"},
                                             {'9', "wxyz"}};

            vector<string> comb;
            string s = "";

            combination(digits, dict, comb, 0, s);

            return comb;
        }
        void combination(const string digits, const unordered_map<char, string> dict, vector<string>& comb, int index, string& s){
            
            //边界条件：访问完所有的数字，得到一个完整字符串时
            if(index == digits.length()){
                comb.push_back(s);
                return;
            }
            
            const string letters = dict.at(digits[index]);
            for(const char letter : letters){
                    s += letter;  // a + e
                    combination(digits, dict, comb, index+1, s); // a + e + h
                    s.pop_back(); //a, 下一次为a + f
            }
        }
};


