#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Group anagrams from the given list of strings.
     *
     * This method takes a vector of strings and groups anagrams together. Anagrams are words or phrases formed by
     * rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
     *
     * @param strs A vector of strings to group anagrams from.
     * @return A vector of vector of strings, where each inner vector represents a group of anagrams.
     */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for (const string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());

            mp[key].push_back(str);
        }

        for (const auto& pair : mp) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Group anagrams using the Solution class
    vector<vector<string>> result = solution.groupAnagrams(strs);

    // Display the grouped anagrams
    for (const vector<string>& group : result) {
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
