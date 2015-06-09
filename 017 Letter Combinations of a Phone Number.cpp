class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<char>> dict
        {
            {'1',{' '}},
            {'2',{'a','b','c'}},
            {'3',{'d','e','f'}},
            {'4',{'g','h','i'}},
            {'5',{'j','k','l'}},
            {'6',{'m','n','o'}},
            {'7',{'p','q','r','s'}},
            {'8',{'t','u','v'}},
            {'9',{'w','x','y','z'}},
            {'0',{' '}},
        };
        vector<string> result;
        if(digits.size()==0) return result;
        DFS(0, digits, dict, result, "");
        return result;
    }
    void DFS(int depth,string digits,unordered_map<char,vector<char>> &dict, vector<string>& result,string solution)
    {
        if(depth==digits.size()) {result.push_back(solution);return;}
        
        for(auto letter:dict[digits[depth]])
        {
            DFS(depth+1,digits, dict, result, solution+letter);
        }
    }
};
