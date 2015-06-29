class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int left=0, right=n-1;
        while(left<right)
        {
            int sum=numbers[left]+numbers[right];
            if(sum==target) 
            {
              vector<int> result; 
              result.push_back(1+left);
              result.push_back(1+right);
              return result;
            }
            if(sum<target) ++left;
            else --right;
        }
    }
};
