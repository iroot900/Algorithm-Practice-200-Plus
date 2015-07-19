//  DFS and backTracking.
//  DFS and memorization.--- > like tree' height issue. go deep when back track update info, choose all path info then return.

int DFS(int x,int y, const vector<vector<int>>& mat, vector<vector<int>>& len)
{
    if(len[x][y]) return len[x][y];
    pair<int,int> pairs[4]={ {-1,0},{0,-1},{0,1},{1,0}};
    int mlen=0;
    for(auto pir:pairs)
    {
        int xx=x+pir.first; int yy=y+pir.second;
        if(xx>=0&&xx<mat.size()&&yy>=0&&yy<mat.front().size()&&mat[xx][yy]==mat[x][y]+1)
        mlen=max(mlen,DFS( xx, yy, mat, len));
    }
    len[x][y]=mlen+1;
    return mlen+1;
}

vector<int> longest_seq(const vector<vector<int>>& mat) {
    vector<int> result;
    int m=mat.size(); if(m==0) return result;
    int n=mat.front().size(); 
    vector<vector<int>> len(m,vector<int> (n,0));
    int mlen=-1;
    int start=-1;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            int length=DFS( i, j, mat, len);
            if(length>mlen)
            {
                mlen=length;start=mat[i][j];
            }
        }
    }
    result.resize(mlen);
    for(int i=start;i<mlen+start;++i)
    {
        result[i-start]=i;
    }
    return result;
}
