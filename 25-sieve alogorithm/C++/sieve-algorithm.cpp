#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 10;
vector<bool> isprime(N,1);


int main(){
  
    isprime[0]=false;isprime[1]=false;
    for(int i=2; i<N; i++){
        if(isprime[i]==true){
            for(int j = 2*i; j<N; j+=i){
                isprime[j]= false;
            }
        }
    }


    // Input the number to check whether prime or not

    ll x;
    cin>>x;

    if(!isprime[x]){
        cout<<x<<" is not prime number"<<endl;
    }else{
         cout<<x<<" is prime number"<<endl;
    }

  return 0;
}