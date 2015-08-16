class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> sta;
        int last=INT_MIN;
        
        for(auto num:preorder)
        {
            if(num<last) return false;
            while(!sta.empty()&&num>sta.top())
            {
                last=sta.top(); sta.pop();
            }
            sta.push(num);
        }
        return true;
    }
};
