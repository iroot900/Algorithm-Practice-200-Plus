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
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(begin(intervals),end(intervals),[](Interval a, Interval b) {return a.start<b.start;});
        
        vector<Interval> result;
        int n=intervals.size();
        if(n==0) return result;
        Interval cur=intervals[0];
        for(int i=1;i<n;++i)
        {
            if(cur.end<intervals[i].start)
            {
             result.push_back(cur);
             cur=intervals[i];
            }
            else
            {
                cur.end=max(cur.end,intervals[i].end);
            }
        }
        result.push_back(cur);
        return result;
    }
};
