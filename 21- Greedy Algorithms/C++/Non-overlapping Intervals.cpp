// This function is used to compare two intervals based on their second element.
bool compare(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

class Solution {
public:
    // This function takes a vector of intervals and returns the minimum number of intervals to remove
    // in order to make all remaining intervals non-overlapping.
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int l = intervals.size();
        
        // Sort the intervals based on their second element using the custom compare function.
        sort(intervals.begin(), intervals.end(), compare);
        
        int cnt = 1; // Initialize the count of non-overlapping intervals with 1 (the first interval).
        int prev = 0; // Initialize a variable to keep track of the previous non-overlapping interval.
        
        // Iterate through the sorted intervals starting from the second interval.
        for(int i = 1; i < l; i++)
        {
            // If the current interval does not overlap with the previous one, update prev and increment cnt.
            if(intervals[i][0] >= intervals[prev][1])
            {
                prev = i;
                cnt++;
            }
        }
        
        // Return the number of intervals to be removed in order to make the remaining ones non-overlapping.
        return l - cnt;
    }
};
