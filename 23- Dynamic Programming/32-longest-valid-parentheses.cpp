/*

32. Longest Valid Parentheses
Difficulty: Hard
Link: https://leetcode.com/problems/longest-valid-parentheses/description/

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses
substring
.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:

Input: s = ""
Output: 0

 

Constraints:

    0 <= s.length <= 3 * 104
    s[i] is '(', or ')'.
*/

#include<bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) {
    int n = s.size();

    // Valid parentheses is of minimum 2 length
    if(n<=1) return 0;

    // Store the longest valid parentheses ending at that index
    int dp[n];

    // Starting is zero
    dp[0]=0;

    // If starting is '()' then longest is 2 else 0 ending at index '1'
    if(s[1]==')' && s[0]=='(') dp[1]=2;
    else dp[1]=0;
    int mx = dp[1];

    // Go through all indices and calculate longest valid parentheses ending at that index
    for(int i=2;i<n;i++) {
    	// If '(' then it cannot be valid
        if(s[i]=='(') dp[i]=0;
        else {
        	// if previous character is '(' then it is valid and longest is 2 + longest till index-2
            if(s[i-1]=='(') dp[i]=dp[i-2]+2;

            // Find starting of longest valid ending at index-1 and see if prev character to that is '('
            else if(i-dp[i-1]-1>=0 and s[i-dp[i-1]-1]=='(') {
                dp[i] = dp[i-1]+2;

                // Also checking if longest valid starting is preceeded by another valid substring
                if(i-dp[i-1]-2>=0) dp[i] += dp[i-dp[i-1]-2];
            }
            else dp[i]=0;
        }
        mx=max(mx,dp[i]);
    }
    return mx;
}

int main() {
	string s;
	cout<<"Enter String: ";
	cin>>s;
	cout<<"Longest Valid Parentheses Length: "<<longestValidParentheses(s)<<"\n";
	return 0;
}

/*
How to run file
1. Run: g++ 32-longest-valid-parentheses.cpp -o valid-paren
2. Run: ./valid-paren
*/