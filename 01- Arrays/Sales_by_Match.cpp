//  https://www.hackerrank.com/challenges/sock-merchant/problem?h_r=next-challenge&h_v=zen
// Complete the sockMerchant function below.

// This function takes an integer n and a vector of integers ar as input
int sockMerchant(int n, vector<int> ar) {
    // Calculate the length of the input vector
    int len = ar.size();

    // Create an unordered map to store the count of each unique integer in the vector
    unordered_map<int, int> mp;

    // Populate the map with the count of each unique integer in the vector
    for(int i = 0; i < len; i++) {
        mp[ar[i]]++;
    }

    // Initialize a variable 'solution' to keep track of the total number of pairs
    int solution = 0;

    // Iterate through the elements in the map
    for(auto x : mp) {
        // If there's only one sock of a particular type, it cannot form a pair, so continue
        if(x.second == 1)
            continue;

        // If there are an odd number of socks of a particular type, we can pair all but one
        if(x.second % 2 != 0) {
            x.second--;
        }

        // Calculate the number of pairs that can be formed from the given count of socks
        solution += x.second / 2;
    }

    // Return the total number of pairs that can be formed from the input socks
    return solution;
}
