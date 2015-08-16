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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(begin(intervals), end(intervals), [] (Interval left, Interval right) {return left.end<right.end ;} );
        
        int n=intervals.size(); if(n==0) return true;
        
        int end=intervals[0].end;
        for(int i=1;i<n;++i)
        {
            if(end>intervals[i].start) return false;
            end=intervals[i].end;
        }
        return true;
    }
};
