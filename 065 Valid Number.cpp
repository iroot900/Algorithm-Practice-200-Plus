class Solution {
public:
    // some says should use a finte state machine for this. 
    // well, I would say solve the problem you have 
    bool isNumber(string s) {
        int n=s.size();
        int i=0;
        while(s[i]==' ') ++i;
        while(s[n-1]==' ') --n;
        if(i>=n) return false;
        bool DFLAG=false, EFLAG=false;
        int start=i;
        for(;i<n;++i)
        {
            switch(s[i])
            {
                case '+':
                case '-':
                //can't be last and not follow e E
                    if(i>start&&(s[i-1]!='e'&&s[i-1]!='E')
                    ||(i+1==n)
                    )
                    return false;
                     break;
                case '.':
                // rules for '.' is wired. 
                // can't be start. can't be standalone, with both side no number. 
                // can't be after . E e
                    if(DFLAG||EFLAG||((i==start||!isdigit(s[i-1]))&&(i==n-1||!isdigit(s[i+1]))))
                    return false;
                    DFLAG=true;
                     break;
                case 'e':
                case 'E':
                // can't be start or last , can't be more. 
                // must have number or (valid '.'-->is a number) before. --> which means can't have sign before!! 
                    if(EFLAG||i==start||i==n-1||s[i-1]=='+'||s[i-1]=='-')
                    return false;
                    EFLAG=true;
                    break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                break;
                default:
                return false;
            }
        }
        return true;
    }
};
