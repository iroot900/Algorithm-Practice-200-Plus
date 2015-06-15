class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        //info. justify  1. len, 2. extra space,left more, 3. last line don't just. 
        // last line 
        // i==last. 
        // words
        vector<string> result;
        int n=words.size();
        vector<string> wrds; int len=0;
        for(int i=0;i<n;)
        {
            if(len==0)
            {
                wrds.push_back(words[i]);
                len+=words[i].size();
                ++i;
            }
            else
            {
                int sz=words[i].size();
                if(len+sz+1<=maxWidth) 
                {
                    wrds.push_back(words[i]);
                    len+=words[i].size()+1;
                    ++i;
                }
                else 
                {
                    int space=maxWidth-len;
                    int num=wrds.size();
                    if(num==1) 
                    {
                        string line=wrds[0];
                        line.append(space,' ');
                        wrds.clear();
                        result.push_back(line);
                        len=0;
                        continue;
                    }
                    int avg=space/(num-1);
                    int extra=space%(num-1);
                    string line=wrds[0];
                    for(int i=1;i<num;++i)
                    {
                        line.append(1,' ');
                        line.append(avg,' ');
                        if(extra)
                        {line.append(1,' '); --extra;}
                        line+=wrds[i];
                    }
                    result.push_back(line);
                    wrds.clear();
                    len=0;
                }
            }
        }
        string lastLine=wrds[0];
        for(int i=1;i<wrds.size();i++)
        {
            lastLine+=" ";
            lastLine+=wrds[i];
        }
        lastLine.append(maxWidth-lastLine.size(),' ');
        result.push_back(lastLine);
        return result;
    }
};
