class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size(), m=num2.size();
        vector<int> digits(m+n-1,0);
        
        reverse(begin(num1),end(num1));
        reverse(begin(num2),end(num2));
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;j++)
            {
                digits[i+j]+=(num1[i]-'0')*(num2[j]-'0');
            }
        }
        
        string result;
        int carry=0;
        int digit=0;
        for(int i=0;i<m+n-1;++i)
        {
            digit=(carry+digits[i])%10;
            carry=(carry+digits[i])/10;
            result.push_back(digit+'0');
        }
        if(carry!=0)
        result.push_back(carry+'0');
        
        while(result.back()=='0'&&result.size()>1)
        result.pop_back();
        
        reverse(begin(result),end(result));
        
        return result;
    }
};
