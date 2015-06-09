class Solution {
public:
    int myAtoi(string str) {
        long sum=0;
        int n=str.size();
        
        //space and sign
        int i=0;
        while(i<n&&str[i]==' ') ++i;
        bool sign=true;
        bool overflow=false;
        if(i<n&&str[i]=='-') {sign=false;++i;}
        else if(i<n&&str[i]=='+') {++i;}
        
        for(i;i<n;i++)
        {
            if(!isdigit(str[i])) break;
            sum=sum*10+str[i]-'0';
            if(sign&&sum>INT_MAX) {overflow=true;break;}
            if(!sign&&-sum<INT_MIN) {overflow=true;break;}
        }
        
        if(sign) return overflow?INT_MAX:sum; 
        return  overflow?INT_MIN:-sum;
    }
};
