#include<bits/stdc++.h>
using namespace std;
int countSubarrWithEqualZeroAndOne(int arr[],int n){
    unordered_map<int,int>um;
    int curr_sum=0;
    for(int i=0;i<n;i++){
        curr_sum+=(arr[i]==0)?-1:arr[i];
        um[curr_sum]++;
    }
    int count=0;
    for(auto itr=um.begin();itr!=um.end();itr++){
        if(itr->second>1)
        count+=((itr->second*(itr->second-1))/2);
    }
    if(um.find(0)!=um.end())
    count+=um[0];
    return count;
}
int main(){
    int arr[]={1,0,0,1,0,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Count="<<countSubarrWithEqualZeroAndOne(arr,n);
    return 0;
}