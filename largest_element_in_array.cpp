// coding ninjas question 


https://www.codingninjas.com/studio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    sort(arr.begin(),arr.end());
    return arr[n-1];
}
