/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        //info  points -- > find max on a line 
        // logic . two points a line. --> a point a k. 
        // all line. 
        //n^2; to visit all line. .. record of line --> k? not..  point a. --> a line. 
        
        //same points..
        //k=MAX;
        
        int maxp=1;
        int n=points.size();
        if(n<3)  return n;
        for(int i=0;i<n;++i)
        {
            unordered_map<double,int> numPoints;
            int vert=0;
            int same=0;
            int x=points[i].x, y=points[i].y;
            for(int j=0;j<n;++j)
            {   //k=deltay/dealtx
                if(i!=j)
                {
                    if(x==points[j].x&&y==points[j].y)
                    {
                        ++same;
                    }
                    else if(x==points[j].x)
                    {
                        ++vert;
                    }
                    else
                    {
                        double k=(double)((y-points[j].y))/(x-points[j].x);
                        numPoints[k]++;
                    }
                }
            }
          //  auto it=max_element(begin(numPoints),end(numPoints),[](pair<double,int> left, pair<double,int> right){ return left.second<right.second;});
            for(auto pnt:numPoints)
            maxp=max(maxp,pnt.second+same);
            maxp=max(vert+same,maxp);
        }
        return maxp+1;
    }
};
