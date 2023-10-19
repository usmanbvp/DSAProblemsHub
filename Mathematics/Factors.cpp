/*
    A C++ program to find all factors of a given number in O(sqrt(n)) time complexity
    and storing the factors in a vector data structure.
    @author [Abdul Kadir](https://github.com/AK3847)
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long; //using long long data structure for large numbers 

void allfacts(ll n, vector<ll> &v){
    for(ll i=1; i<=sqrt(n); ++i){
        if(n%i==0){
        if(n/i==i)
            v.push_back(i);
        else{
            v.push_back(i);
            v.push_back(n/i);
        }
}}}
int main()
{
    ll num;
    cout<<"Give your number: ";
    cin>>num;
    vector<ll> factors;
    allfacts(num,factors);
    sort(factors.begin(),factors.end());
    ll sz=factors.size();
    cout<<"The factors of given number "<<num<<" are:\n";
    for(ll it=0;it<sz;it++)
    {
        cout<<factors[it]<<(it==sz-1?"\n":" ");
    }
    return 0;
}