/*
2416. Sum of Prefix Scores of Strings
Link - https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/

You are given an array words of size n consisting of non-empty strings.
We define the score of a string word as the number of strings words[i]
such that word is a prefix of words[i].

For example, if words = ["a", "ab", "abc", "cab"],
then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
Return an array answer of size n where answer[i] is the sum of scores
of every non-empty prefix of words[i].

Note that a string is considered as a prefix of itself.

Example 1:

Input:
4
abc
ab
bc
b

Output: 5 4 3 2

Explanation: The answer for each string is the following:
- "abc" has 3 prefixes: "a", "ab", and "abc".
- There are 2 strings with the prefix "a", 2 strings with the prefix "ab", and 1 string with the prefix "abc".
The total is answer[0] = 2 + 2 + 1 = 5.
- "ab" has 2 prefixes: "a" and "ab".
- There are 2 strings with the prefix "a", and 2 strings with the prefix "ab".
The total is answer[1] = 2 + 2 = 4.
- "bc" has 2 prefixes: "b" and "bc".
- There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
The total is answer[2] = 2 + 1 = 3.
- "b" has 1 prefix: "b".
- There are 2 strings with the prefix "b".
The total is answer[3] = 2.

Example 2:

Input:
1
abcd

Output: 4

Explanation:
"abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 = 4.
*/

#include<bits/stdc++.h>

using namespace std;

// Trie Node
struct node {
    int val;
    map<char,node*> m;
    node(int x) {
        val = x;
    }
};

// Add strings to Trie while incrementing 'val' with 1
// for every string that passes through that node
void add(string &s, node *n) {
    for(int i=0;i<s.size();i++) {
        if(n->m.find(s[i]) == n->m.end()) n->m[s[i]] = new node(0);
        n = n->m[s[i]];
        n->val++;
    }
    return;
}

// Get Score of individual String by getting 'val' 
// which count all words that contain prefix till that node
int getScore(string &s, node *n) {
    int score = 0;
    for(int i=0;i<s.size();i++) {
        n = n->m[s[i]];
        score += n->val;
    }
    return score;
}

// Get Sum of Prefix Scores
vector<int> sumPrefixScores(vector<string>& words) {
    vector<int> v;
    node *root = new node(0);
    for(auto s: words) {
        add(s, root);
    }
    for(auto s: words) {
        v.push_back(getScore(s, root));
    }
    return v;
}

// Driver Function to take input and print output
int main() {
    int n;  // Number of Words
    cout<<"Number of Words: ";
    cin>>n;
    vector<string> words;
    cout<<"Enter Words:\n";
    for(int i=0;i<n;i++) {
        string p;
        cin>>p;
        words.push_back(p);
    }

    vector<int> scores = sumPrefixScores(words);
    cout<<"Sum of Prefix Scores: ";
    for(auto i: scores) {
        cout<<i<<" ";
    }
    cout<<"\n";

    return 0;
}