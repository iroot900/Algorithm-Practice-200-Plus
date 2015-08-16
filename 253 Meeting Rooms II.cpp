/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        int n=intervals.size(); if(n<2) return n;
        
        vector<int> bound;
        for(auto inter:intervals) 
        {
            bound.push_back(inter.start);
            bound.push_back(-inter.end);
        }
        
        sort(begin(bound), end(bound), [](int left, int right) { 
            if(left==-right) return left<right;
            return abs(left)<abs(right);
        ;} );
        
        int count=0;
        int mmax=0;
        for(int i=0;i<bound.size();++i)
        {
            if(bound[i]>=0)  {++count; mmax=max(mmax,count);}
            else --count;
        }
        return mmax;
    }
};
