#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ninjaTraining(int n, vector<vector<int>> &points)
{
     vector<int> prev(4, 0);
    for (int i = 0; i <= 3; i++)
    {
        for (int last = 0; last < 3; last++)
        {
            if(last != i) prev[i] = max(prev[i], points[0][last]);
        }
    }

    for (int day = 1; day < n; day++)
    {
        vector <int> temp(4, 0);
        for (int last = 0; last <= 3; last++)
        {
            temp[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if(task != last) temp[last] =  max(temp[last], points[day][task] + prev[task]);
            } 
        }
        prev = temp;
    }
    
    return prev[3];
}