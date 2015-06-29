class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        if(n==0) return result;
        pair<int,int> candidateA(nums[0],1),
        candidateB(LONG_MAX,0);
        for(int i=1;i<n;++i){   
            //if there are equal 
            if(candidateA.first==nums[i])
            {  
                candidateA.second++; continue; 
            }
            
            if(candidateB.first==nums[i]){
            candidateB.second++; continue;
            }
            
            if(candidateB.second==0)
            {
                candidateB.first=nums[i];
                candidateB.second=1;
                continue;
                
            }
            
            if(candidateA.second==0)
            {
                candidateA.first=nums[i];
                candidateA.second=1; continue; 
            }
            
            candidateA.second--;
            candidateB.second--;
            
        }
        
        int countA=0, countB=0;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==candidateA.first) ++countA;
            if(nums[i]==candidateB.first) ++countB;
        }
        if(countA>n/3) result.push_back(candidateA.first);
        if(countB>n/3) result.push_back(candidateB.first);
        return result;
    }
};
