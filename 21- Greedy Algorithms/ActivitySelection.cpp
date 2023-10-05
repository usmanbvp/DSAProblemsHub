//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


struct Activity
{
    int start;
    int end;
};


class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool compare(Activity a, Activity b)
    {
        if(a.end < b.end) return 1;
        else if(a.end == b.end && a.start < b.start) return 1;
        else return 0;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        Activity arr[n];
        
        for(int i = 0; i < n; i++)
        {
            arr[i].start = start[i];
            arr[i].end = end[i];
        }
        
        sort(arr, arr+n, compare);
        
        int count = 1;
        int j = 0;
        for(int i = 1; i < n && j < n; i++)
        {
            if(arr[i].start > arr[j].end)
            {
                count++;
                j = i;
            }
        }
        
        return count;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
