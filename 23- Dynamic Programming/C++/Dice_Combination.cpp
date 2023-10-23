#include<bits/stdc++.h>
using namespace std;
 
#define int long long int
 
const int M =1e9+7;
int dp[1000001];
int solve(int n){
    if(n==0) return 1;
    if(dp[n]!=0) return dp[n];
    int ans=0;
    for(int i=1;i<=6;i++){
        if(n-i>=0){
        ans+=solve(n-i);
        ans%=M;
        }
    }
    return dp[n]=ans;
}
 
int32_t main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
   int n;
   cin>>n;
   memset(dp,0,sizeof(dp));
   int total = solve(n);
   cout<<total<<endl;
 
}
