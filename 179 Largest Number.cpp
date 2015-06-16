class Solution {
public:
    struct compare
    {
        public:
        bool operator () (int a,int b) const
        {
            return (to_string(a)+to_string(b))<(to_string(b)+to_string(a)) ;
        }
    };
    string largestNumber(vector<int>& nums) {
        if(nums.size()==0) return string();
        //sort(begin(nums),end(nums),[](int a,int b){return (to_string(a)+to_string(b))>(to_string(b)+to_string(a)) ;});
        priority_queue<int,vector<int>,compare> data;
        for(auto x:nums)
        {
            data.push(x);
        }
        string result="";
        while(!data.empty())
        {
            result+=to_string(data.top());
            data.pop();
        }
        if(result[0]=='0') return string(1,'0');
        return result;
    }
};
