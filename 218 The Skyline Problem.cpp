class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        // sky line problem 
        int n=buildings.size();
        if(n==0) return {vector<pair<int,int>> ()};
        auto result= Skyline(buildings, 0, n-1);
        return remove(result);
    }
    
    vector<pair<int,int>> Skyline(vector<vector<int>>& buildings,int left, int right)
    {
        if(left==right) 
        {
            return { {buildings[left][0],buildings[left][2]}, {buildings[left][1],0}};
        }
        int mid=(left+right)>>1;
        auto leftSky=Skyline( buildings, left,  mid);
        auto rightSky=Skyline( buildings, mid+1,  right);
        return merge( leftSky,rightSky );
    }
    
    vector<pair<int,int>> merge( const vector<pair<int,int>> & leftSky, const vector<pair<int,int>> & rightSky)
    {
        int left=leftSky.size();
        int right=rightSky.size();
        int i=0,j=0;
        
        vector<pair<int,int>> result;
        int leftH=0, rightH=0;
        while(i<left&&j<right)
        {
            if(leftSky[i].first<rightSky[j].first)
            {
                leftH=leftSky[i].second;
                result.push_back(make_pair( leftSky[i].first,max(leftH,rightH)  ));
                ++i;
            }
            else if(leftSky[i].first>rightSky[j].first)
            {
                rightH=rightSky[j].second;
                result.push_back(make_pair( rightSky[j].first,max(leftH,rightH)  ));
                ++j;
            }
            else 
            {
                leftH=leftSky[i].second;
                rightH=rightSky[j].second;
                result.push_back(make_pair( rightSky[j].first,max(leftH,rightH)  ));
                ++i;++j;
            }
        }
        
        while(i<left) { result.push_back(make_pair( leftSky[i].first,leftSky[i].second)); ++i; }
        while(j<right) { result.push_back(make_pair( rightSky[j].first,rightSky[j].second )); ++j; }
        
        return result;
    }
    
    vector<pair<int,int>>  remove(vector<pair<int,int>> & result)
    {
        vector<pair<int,int>> ret;
        for(auto line:result)
        {
            if(ret.empty())
            {
                ret.push_back(line);
            }
            else if(line.second!=ret.back().second)
            {
                ret.push_back(line);
            }
        }
        return ret;
    }
