// Kadanes Algorithm

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxsumSubArray(int a[],int n)
{
    int maxsum = a[0];
    int cursum=0;
    for(int i=01;i<n;i++)
    {
        cursum = cursum+ a[i];
        if(cursum> maxsum)
            maxsum= cursum;
        if(cursum<0)
            cursum = 0;
    }
    return maxsum;
}

int main()
{
    int arr[6]={-5,4,6,-3,4,-1};
    int ans=maxsumSubArray(arr,6);
    cout<<ans;
    return 0;
}