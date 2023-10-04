//leetcode
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        int count = 0;
        int singleNum = 0;
        for (auto x : freq) {
            if (x.second == 1) {
                singleNum = x.first;
                break;
            }
        }
        return singleNum;
    }
};