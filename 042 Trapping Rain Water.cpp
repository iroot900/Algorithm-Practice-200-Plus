class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> sta;
        
        int n=height.size();
        int water=0;
        for(int i=0;i<n;)
        {
            if(sta.empty()||height[i]<height[sta.top()])
            {
                sta.push(i);++i;
            }
            else
            {
                int temp=sta.top(); sta.pop();
                if(sta.empty()) continue;
                water+= (min(height[i],height[sta.top()])-height[temp])*(i-sta.top()-1);
            }
        }
        return water;
    }
};
