/*
    A C++ program to convert given string as input into integer as output
    using recursive function and bit shifting
    @author [Abdul Kadir](https://github.com/AK3847)
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long; //using Long long data type to store Large Integers.

ll BinarytoInteger(string s,ll len, ll i=0) //User-defined function for converting Binary to Integer
{
    if(len==i+1)    return (s[i]-'0'); //terminating condition
    ll temp=s[i]-'0';
    temp=temp<<len-i-1; //bit shifting
    temp+=BinarytoInteger(s,len,i+1); //recursive call
    return temp;
}

bool check(string s) //User-defined function for checking if given string is binary or not
{ 
    for(auto it:s){ 
        if(it-'0'!=1 && it-'0'!=0) 
            return 0; 
    }
    return 1;
}
int main()
{
    string s;
    cout<<"Give your String: "; //string input
    cin>>s;
    ll Integer=BinarytoInteger(s,s.size()); //function call
    if(check(s))
    {
        cout<<"Converted Integer is: "<<Integer;
    }
    else
        cout<<"Give a binary string (only 1s & 0s).\n";
    return 0;
}