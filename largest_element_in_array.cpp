// coding ninjas question 

#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    sort(arr.begin(),arr.end());
    return arr[n-1];
}
