class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t startA=0, startB=0;
        // main logic, one side is over then it's over,   difference, then it's over. 
        // 
        while(1)
        {
            string left, right;
            auto p=version1.find_first_of(".",startA);
            if(p!=string::npos) {left=version1.substr(startA,p-startA); startA=p+1;}
            else if(startA!=version1.size()) {left=version1.substr(startA);startA=version1.size();}
            else {left="0";}
            
            auto pp=version2.find_first_of(".",startB);
            if(pp!=string::npos) {right=version2.substr(startB,pp-startB); startB=pp+1;}
            else if(startB!=version2.size()) {right=version2.substr(startB);startB=version2.size();}
            else {right="0";}
            
            if(stoi(left)<stoi(right)) return -1;
            if(stoi(right)<stoi(left)) return 1;
            if(p==string::npos&&pp==string::npos) return 0;
        }
        return 0;
    }
};
