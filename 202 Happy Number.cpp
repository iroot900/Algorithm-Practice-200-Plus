class Solution {
public: 
    bool isHappy(int n) {
         int pre=n,cur=n;
         unordered_set<int> data;
         while(cur!=1)
         {
             if(data.find(cur)!=data.end()) return false;
             data.insert(cur);
             pre=cur;
             cur=0;
             while(pre)
             {
                 cur+=(pre%10)*(pre%10);
                 pre=pre/10;
             }
         }
         return true;
    }
};
