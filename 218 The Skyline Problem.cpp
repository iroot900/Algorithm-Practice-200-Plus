class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> skylines;
        int n=buildings.size(); 
        if(n==0) return skylines;
        return divider(buildings, 0, n-1);
    }
    
    vector<pair<int,int>> divider(const vector<vector<int>>& buildings, int left, int right)
    {
        if(left==right)
        {
            vector<pair<int,int>> ret;
            ret.push_back(make_pair(buildings[left][0],buildings[left][2]));
            ret.push_back(make_pair(buildings[left][1],0));
            return ret;
        }
       
        int mid=(left+right)>>1;
        auto skyLeft=divider(buildings, left, mid); // there is no "-", so all's good!!!
        auto skyRight=divider(buildings, mid+1, right);
        return merge(skyLeft, skyRight);
    }
    
    vector<pair<int,int>> merge(const vector<pair<int, int>> &skyLeft, const vector<pair<int, int>> &skyRight)
    {
        vector<pair<int, int>> result;
        int m=skyLeft.size(), n=skyRight.size();
        int left=0, right=0;
        
        int leftH=0, rightH=0;
        while(left<m||right<n)
        {
            if(left<m&&right<n)
            {
                if(skyLeft[left].first<skyRight[right].first)
                {
                    auto P=skyLeft[left].first;
                    auto H=max(skyLeft[left].second,rightH);
                    // outside logic --- update P and H. 
                    // inside logic. --- H compare P compare. 
                    // don't combine
                    if(result.size()>0)
                    {
                        if(result.back().second==H) 
                        { }
                        else if(result.back().first==P)
                           result.back().second=H;// not again. max 
                        else 
                           result.push_back(make_pair(P,H));
                    }
                    else
                    result.push_back(make_pair(P,H));
                    leftH=skyLeft[left].second;
                    ++left;
                }
                else
                {
                    auto P=skyRight[right].first;
                    auto H=max(skyRight[right].second,leftH);
                    if(result.size()>0)
                    {
                        if(result.back().second==H) 
                        { }
                        else if(result.back().first==P)
                           result.back().second=H;
                        else   
                           result.push_back(make_pair(P,H));
                    }
                    else
                    result.push_back(make_pair(P,H));
                    rightH=skyRight[right].second;
                    ++right;
                }
            }
            else if(left<m)
            {
                    auto P=skyLeft[left].first;
                    auto H=max(skyLeft[left].second,rightH);
                    if(result.size()>0)
                    {
                        if(result.back().second==H) 
                        { }
                        else if(result.back().first==P)
                           result.back().second=H;
                        else  
                           result.push_back(make_pair(P,H));
                    }
                    else
                    result.push_back(make_pair(P,H));
                    leftH=skyLeft[left].second;
                    ++left;
            }
            else 
            {
                    auto P=skyRight[right].first;
                    auto H=max(skyRight[right].second,leftH);
                    if(result.size()>0)
                    {
                        if(result.back().second==H) 
                        { }
                        else if(result.back().first==P)
                           result.back().second=H;
                        else  
                           result.push_back(make_pair(P,H));
                    }
                    else
                    result.push_back(make_pair(P,H));
                    rightH=skyRight[right].second;
                    ++right;
            }
        }
        // unique it..
        return result;
    }
};
