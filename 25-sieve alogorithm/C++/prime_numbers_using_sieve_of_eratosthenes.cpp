#include <bits/stdc++.h> 
using namespace std; 

void SieveOfEratosthenes(int n) 
{ 
	bool prime[n + 1]; 
	memset(prime, 1, sizeof(prime)); 

	for (int p = 2; p*p <= n; p++) { 
		if (prime[p] == true) { 
			for (int i = p * p; i <= n; i += p) 
				prime[i] = 0; 
		} 
	} 
	for (int p = 2; p <= n; p++) 
		if (prime[p]) 
			cout << p << " "; 
} 

int main() 
{ 
    cout<<"enter a number till which you want to find prime numbers"<<endl;
    int n;
    cin>>n; 
	cout << "Following are the prime numbers less than or equal to "<<n<< endl; 
	SieveOfEratosthenes(n); 
	return 0; 
}
