class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int,pair<int,int>> seqDict;
        int n=s.size();
        vector<string> result;
        if(n<10) return result;
        int last=0;
        
        for(int i=0;i<10;i++)
        {
            last=last*4+tran(s[i]);
        }
        seqDict[last].first=0;
        seqDict[last].second++;
        for(int i=1;i<=n-10;++i)
        {
            last-=tran(s[i-1])*pow(4,9);
            last=last*4+tran(s[i+9]);
            seqDict[last].first=i;
            seqDict[last].second++;
        }
        
        for(auto seq:seqDict)
        {
            if(seq.second.second>1) result.push_back(s.substr(seq.second.first,10));
        }
        return result;
    }
    
    int tran(char cha)
    {
        switch(cha)
        {
            case 'A':
            return 1;
            case 'C':
            return 2;
            case 'G':
            return 3;
            case 'T':
            return 4;
        }
    }
};
