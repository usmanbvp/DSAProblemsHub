#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

// a<=1e9 , b<=1e9 , M<=1e9 
int binExpoIter(int a,int b){
   int ans = 1;
   while(b){
      if(b&1){
         ans=(ans*a);
      }
      a=(a*a);
      b >>= 1;
   }
   return ans;
}

int32_t main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int a,b;
cout<<"enter base"<<endl;
cin>>a;
cout<<"enter power"<<endl;
cin>>b;
cout<<"a to the power b is ";
cout<<binExpoIter(a,b);

}