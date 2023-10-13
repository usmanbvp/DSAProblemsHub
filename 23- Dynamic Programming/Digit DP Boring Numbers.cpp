#include<bits/stdc++.h>
using namespace std;

string s;
int64_t n;
int64_t dp[20][2][2][20] = {};

int64_t go(int64_t curr, int64_t n, int64_t tight = 1, int64_t leading_zero = 0, int64_t cnt = 1){
	if(curr == n){
		return 1;
	}

	if(dp[curr][tight][leading_zero][cnt]!=-1) return dp[curr][tight][leading_zero][cnt];

	int64_t ans = 0;
	int64_t upper_bound = 9;
	if(tight == 1){
		upper_bound = s[curr] - '0';
	}
	for(int64_t i=0;i<=upper_bound;i++){
		if((i!=0 or leading_zero) and cnt%2 == i%2){
			ans += go(curr+1,n,tight&i==upper_bound,leading_zero||i!=0,cnt+1);
		}
		else if((i!=0 or leading_zero) and cnt%2 != i%2){

		}
		else{
			ans += go(curr+1,n,tight&i==upper_bound,leading_zero||i!=0,cnt);
		}
	}

	return dp[curr][tight][leading_zero][cnt] = ans;
}

int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
	freopen("E:/CODING/input.txt", "r", stdin); 
	freopen("E:/CODING/output.txt", "w", stdout); 
	#endif

	int64_t i,j,t=1;
	cin>>t;
	int64_t T = t;
	while(t--){
		cout << "Case #" << T-t << ": "; 

		cin >> s;
		n = s.size();
		bool ok = 1;
		for(i=0;i<n;i++){
			if((s[i]-'0')%2 != (i+1)%2) ok = 0;
		}
		memset(dp,-1,sizeof dp);
		int64_t left = go(0,n);
		cin >> s;
		n = s.size();
		memset(dp,-1,sizeof dp);
		int64_t right = go(0,n);

		cout << right - left + ok << '\n';
 	}
	
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
