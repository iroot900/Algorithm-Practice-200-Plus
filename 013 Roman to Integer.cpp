class Solution {
public:
    int romanToInt(string s) {
        vector<int> radix={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> base={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        unordered_map<string,int> roman;
        for(int i=0;i<13;i++)
        roman[base[i]]=radix[i];
        
        int result=0;int i=0;
       for(;i<s.size()-1;i++)
       {
          string cur,next;
          cur.push_back(s[i]);
          next.push_back(s[i+1]);
            if(i<int(s.size())-1&&roman[cur]<roman[next])
            {
                string str;
                str.push_back(s[i]);str.push_back(s[i+1]);
                result+=roman[str];i++;
            }
            else
            {
                result+=roman[cur];
            }
       }
       if(i==s.size()-1)
       {
            string cur,next;
            cur.push_back(s[i]);
            result+=roman[cur];
       }
         return result;
    }
  
};
