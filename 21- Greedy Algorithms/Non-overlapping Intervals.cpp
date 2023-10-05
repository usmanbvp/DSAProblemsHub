bool compare(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}
class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int l = intervals.size();
        sort(intervals.begin(),intervals.end(),compare);
        int cnt = 1;
        int prev = 0;
        for(int i=1; i<l; i++)
        {
            if(intervals[i][0] >= intervals[prev][1])
            {
                prev = i;
                cnt++;
            }
        }
        return l - cnt;
    }
};
