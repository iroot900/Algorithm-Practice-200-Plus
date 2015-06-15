class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix.front().size();
        int mmax=0;
        vector<int> heights(n,0);
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j]=='1')
                {
                    heights[j]++;
                }
                else 
                heights[j]=0;
            }
            mmax=max(mmax,maxRect(heights));
        }
        return mmax;
    }
    
    int maxRect(vector<int> &heights)
    {
        stack<int> sta;
        if(heights.size()==0) return 0;
        heights.push_back(0);
        int n=heights.size();
        int marea=0;
        // 2 1 5 6 1 3 
        
        for(int i=0;i<n;)
        {
            if(sta.empty()||heights[i]>=heights[sta.top()])
            {
                sta.push(i);++i;
            }
            else 
            {
                int height=heights[sta.top()]; sta.pop();
                marea=max(marea,(sta.empty()?i:i-sta.top()-1)*height);
            }
        }
        return marea;
    }
};
