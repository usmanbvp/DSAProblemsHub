/*
    A C++ program to find all factors of a given number in O(sqrt(n)) time complexity
    and storing the factors in a vector data structure.
    The factorization algorithm takes O(sqrt(n)) time where n is the given number
    while sorting the vector takesa O(m*log(m)) where m is the number of factors
    Overall time complexity: O(sqrt(n))+O(m*log(m)) 
    but for relatively large number 'n' time complexity can be simplified to: O(sqrt(n))
    @author [Abdul Kadir](https://github.com/AK3847)
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long; //using long long data structure for large numbers 

void allfacts(ll n, vector<ll> &v) //user-defined function to find factors and storing them in a Vector
{
    for(ll i=1; i<=sqrt(n); ++i){
        if(n%i==0){
            if(n/i==i)
                v.push_back(i);
            else{
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
}
int main()
{
    ll num;
    cout<<"Give your number: ";
    cin>>num;
    vector<ll> factors;
    allfacts(num,factors); //calling the user-defined function
    sort(factors.begin(),factors.end()); //sorting the vector so as to get factors in ascending order
    ll sz=factors.size();
    cout<<"The factors of given number "<<num<<" are:\n";
    for(ll it=0;it<sz;it++)
    {
        cout<<factors[it]<<(it==sz-1?"\n":" ");
    }
    return 0;
}