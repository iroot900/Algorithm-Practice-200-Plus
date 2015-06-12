class Solution {
public:
    string addBinary(string a, string b) {
    int m=a.size(),n=b.size();
    int carry=0;
    int digit=0;
    string result;
    while(m||n)
    {
        if(m&&n)
        {
            digit=(a[m-1]-'0'+b[n-1]-'0'+carry)%2;
            carry=(a[m-1]-'0'+b[n-1]-'0'+carry)/2;
            result.push_back(digit+'0');
            --m;--n;
        }
        else if(m)
        {
            digit=(a[m-1]-'0'+carry)%2;
            carry=(a[m-1]-'0'+carry)/2;
            result.push_back(digit+'0');
            --m;
        }
        else 
        {
            digit=(b[n-1]-'0'+carry)%2;
            carry=(b[n-1]-'0'+carry)/2;
            result.push_back(digit+'0');
            --n;
        }
    }
    if(carry)
    result.push_back(carry+'0');
    reverse(begin(result),end(result));
    return result;
    }
};
