class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        
        int mmax=*max_element(begin(nums),end(nums));
        int mmin=*min_element(begin(nums),end(nums));
        int len=ceil((double)(mmax-mmin)/(nums.size()-1));
        //cout<<len;
        
        // 1  )4  ) 7-->only last one not in. 
        vector<pair<int,int>> buckets(nums.size()-1,pair<int,int>(INT_MAX,INT_MIN));// min,max
        
        for(auto x:nums)
        {
            if(x==mmax) continue;
            if(buckets[(x-mmin)/len].first==INT_MAX) {buckets[(x-mmin)/len].first=x;buckets[(x-mmin)/len].second=x;}
            else 
            {
                buckets[(x-mmin)/len].first=min(buckets[(x-mmin)/len].first,x);
                buckets[(x-mmin)/len].second=max(buckets[(x-mmin)/len].second,x);
            }
        }
        
        int gap=0;
        int last=mmin;
        for(auto pir:buckets)
        {
            if(pir.first==INT_MAX) continue;
            gap=max(pir.first-last,gap);
            last=pir.second;
        }
        gap=max(mmax-last,gap);
        
        return gap;
    }
};
