class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int start=0;
        int remain=0;
        int gasV=0,costV=0;
        int i=0;
        for(;i<n;++i)
        {
            if((remain+gas[i])>=cost[i])
            {
                remain+=gas[i]-cost[i];
            }
            else
            {
                start=i+1;
                remain=0;
            }
            gasV+=gas[i];
            costV+=cost[i];
        }
        
        if(gasV<costV) return -1; 
        return start;
    }
};
