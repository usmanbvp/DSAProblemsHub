#include<bits/stdc++.h>
using namespace std;
 
#define int long long int
#define endl "\n"
 
int32_t main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
   int n;
   cin>>n;
   vector<pair<int,int>>v;
   for(int i=0;i<n;i++){
    int b,a;
    cin>>a>>b;
    v.push_back({b,a});
   }
   sort(v.begin(),v.end());
   int ct=1;
   pair<int,int> watched = v[0];
   for(int i=1;i<n;i++){
    if( watched.first<=v[i].second){
        ct++;
        watched= v[i];
    }
   }
   cout<<ct<<endl;
 
}