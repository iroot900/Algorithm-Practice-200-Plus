class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        // main logic:
        // shortest len.  breadth first search look promising.
        // find each nodes neighbors... how to find neighbor, this is where it takes time.
        // check if all in[n*k] and if it's neighbor ???  find if any neibhor is in..[any neibhor ->  each digit is 26*10. 
        //  26*k  n*k    definitely go with 26.  see? it's easy logic. really nice good wonderful staff. 
        // when find return len, or visited all could visited(didn't find then return 0)

        unordered_map<string,int> visited; // also use it to store the level..
        queue<string> que;
        que.push(beginWord);
        visited[beginWord]=1;
        wordDict.erase(beginWord);
        while(!que.empty())
        {
            string word=que.front();
            que.pop();
            
            // delete visited each time so, neighbors will smaller.
            vector<string> neighbors;
            for(int i=0;i<word.size();++i)
            {
                char temp=word[i];
                string origin=word;
                for(char cha='a';cha<='z';++cha)
                {
                    if(temp==cha) continue;
                    word[i]=cha;
                    auto it=wordDict.find(word);
                    if(it!=wordDict.end())
                    neighbors.push_back(word);
                }
                word[i]=temp;
            }
            
            for(auto neighbor:neighbors)
            {
              //  if(visited.find(neighbor)!=visited.end()) continue; // No visited neigbhor, deleted already.
                if(neighbor==endWord) return visited[word]+1; 
                visited[neighbor]=visited[word]+1;
                wordDict.erase(neighbor);
                que.push(neighbor);
            }
        }
        return 0;
    }
};
