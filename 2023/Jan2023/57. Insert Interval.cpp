You are given an array of non-overlapping intervals intervals where 
intervals[i] = [starti, endi] represent the start and the end of the 
ith interval and intervals is sorted in ascending order by starti. 
You are also given an interval newInterval = [start, end] that 
represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted 
in ascending order by starti and intervals still does not have any 
overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

Constraints:
0 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^5
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 10^5

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        for(int i=0;i<intervals.size();i++) {
            
            // ex: intervals = [[2,3],[4,5]] newInterval = [0,1]
            // 1 < 2 then ans = [[0,1], [2,3], [4,5]]
            if(newInterval[1] < intervals[i][0]) {
                ans.push_back(newInterval);
                ans.insert(ans.end(), intervals.begin()+i, intervals.end());
                return ans;
            }
            
            // ex: intervals = [[2,3],[6,8]] newInterval = [4,5]
            // 4 > 3 then ans = [[2,3], ...] // push current interval & continue
            else if(newInterval[0] > intervals[i][1]) {
                ans.push_back(intervals[i]);
            }
            
            // ex: intervals = [[1,3],[6,9]] newInterval = [2,5]
            // merge intervals: [1,3] & [2,5] 
            // newInterval[0] = min(1,2); newInterval[1] = max(3,5) 
            // merged newInterval = [1,5]
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};
