/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n==0) return true;
        sort(intervals.begin(),intervals.end(),[](auto& a, auto& b){
            return a.end<b.end;
        });

        int endtime = intervals[0].end;

        for(int i=1; i<n; i++){
            if(intervals[i].start<endtime) return false;
            endtime = intervals[i].end;
        }
        return true;
    }
};
