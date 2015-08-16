class Solution {
public:
    int minCost(vector<vector<int>>& costs) { 
     int n=costs.size(); if(n==0) return 0; 
     int minR=0, minB=0, minG=0;
     for(int i=0;i<n;++i)
     {
         int minR_temp=costs[i][0]+min(minB,minG);
         int minB_temp=costs[i][1]+min(minR,minG);
         int minG_temp=costs[i][2]+min(minR,minB);
         minR=minR_temp; minB=minB_temp; minG=minG_temp; 
     }
     return min(minB,min(minG,minR));
    }
};
