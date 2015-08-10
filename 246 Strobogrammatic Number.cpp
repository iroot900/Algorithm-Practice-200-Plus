class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> strMap={ {'1','1'}, {'0','0'}, {'6','9'},{'9','6'},{'8','8'} } ;
        int n=num.size();
        string strNum(n,' '); 
        for(int i=0;i<n;++i)
        {
            if(strMap.count(num[i])==0) return false;
            strNum[i]=strMap[num[i]];
        }
        reverse(begin(strNum),end(strNum));
        return num==strNum;
    }
};
