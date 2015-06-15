class Solution {
public:
int largestRectangleArea(vector<int>& height) {
        stack<int> sta;
        int n=height.size();
        height.push_back(0);
        int marea=0;
        
        for(int i=0;i<n+1;)
        {
            if(sta.empty()||height[i]>=height[sta.top()])
            {
                sta.push(i);++i;
            }
            else
            {
                int temp=sta.top(); sta.pop();
                int len=i-(sta.empty()?-1:sta.top())-1;
                marea=max(marea,len*height[temp]);
            }
        }
        return marea;
    }
};
