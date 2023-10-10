#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0; // End word is not in the wordList, no transformation possible.
        }
        
        int ladderLength = 1;
        queue<string> q;
        q.push(beginWord);
        
        while (!q.empty()) {
            int currentLevelSize = q.size();
            
            for (int i = 0; i < currentLevelSize; ++i) {
                string currentWord = q.front();
                q.pop();
                
                // Generate all possible next words by changing one character
                for (int j = 0; j < currentWord.length(); ++j) {
                    char originalChar = currentWord[j];
                    
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue; // Skip the same character
                        currentWord[j] = c;
                        
                        if (currentWord == endWord) {
                            return ladderLength + 1; // Transformation complete
                        }
                        
                        if (wordSet.find(currentWord) != wordSet.end()) {
                            q.push(currentWord); // Add valid word to the queue
                            wordSet.erase(currentWord); // Mark it as visited
                        }
                        
                        currentWord[j] = originalChar; // Restore the word for the next iteration
                    }
                }
            }
            
            ladderLength++;
        }
        
        return 0; // No transformation sequence found
    }
};

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    Solution solution;
    int length = solution.ladderLength(beginWord, endWord, wordList);
    
    if (length > 0) {
        cout << "Shortest ladder length: " << length << endl;
    } else {
        cout << "No transformation sequence found." << endl;
    }
    
    return 0;
}
