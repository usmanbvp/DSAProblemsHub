#include <bits/stdc++.h>
using namespace std;

/*
The sieve of Eratosthenes is a program that finds all primes 
smaller than n in O(n*log(log(n))) time complexity
*/

void SieveOfEratosthenes(int n)
{
    vector<bool> p(n+1,1);

    for (int i = 2; i * i <= n; i++) {
        if (p[i]==1) {
            for (int j = i * i; j <= n; j += i)
                p[j] = 0;
        }
    }

    for (int x = 2; x <= n; x++)
        if (p[x])
            cout << x << " ";
}

int main() {

    int n;
    cin>>n;
    cout<<"The prime numbers smaller than or equal to "<< n<<" are: "<<endl<<endl;
    SieveOfEratosthenes(n);

}
