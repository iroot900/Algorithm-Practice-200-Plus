class Solution {
public:
    int compareVersion(string version1, string version2) {
        int startL=0, startR=0;
        int m=version1.size();
        int n=version2.size();
        string left, right;
        
        // if there are ways to do in human mind, it could be done in logic 
        while(startL!=m||startR!=n)
        {
            int i=0;
            for(i=startL;i<m;++i)
            {
                if(version1[i]=='.')
                {
                    left=version1.substr(startL,i-startL);
                    startL=i+1; break;
                }
            }
            if(i==m&&version1[m-1]!='.')
            {
                left=version1.substr(startL,m-startL);
                startL=m;
            }
            for(i=startR;i<n;++i)
            {
                if(version2[i]=='.')
                {
                    right=version2.substr(startR,i-startR);
                    startR=i+1; break;
                }
            }
            if(i==n&&version2[n-1]!='.')
            {
                right=version2.substr(startR,n-startR);
                startR=n;
            }
            while(left.size()>0&&left[0]=='0') left=left.substr(1);
            while(right.size()>0&&right[0]=='0') right=right.substr(1);
            if(left==""&&right==""&&startL==m&&startR==n) return 0;
            if(left==""&&right=="") continue;
            else if(left=="") return -1;
            else if(right=="") return 1;
            if(stoi(left)>stoi(right)) return 1;
            else if(stoi(left)<stoi(right)) return -1;
        }
        return 0;
    }
};
