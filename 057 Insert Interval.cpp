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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n=intervals.size();
        vector<Interval> result;
        // dealing with data and do thing change, not on the original data. usually. don't over complify it!
        // you can return new data. and use space. if this is the cost, you can afford it. 
        if(n==0)
        {
            result.push_back(newInterval); return result;
        }
        
        int i=0;
        for(;i<n;i++)
        {
            if(newInterval.start<=intervals[i].start) 
            {
                intervals.insert(begin(intervals)+i,newInterval);
                break;
            }
        }
        if(i==n)
        intervals.insert(end(intervals),newInterval);
        
        auto cur=intervals[0];
        
        for(int i=1;i<n+1;++i)
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
