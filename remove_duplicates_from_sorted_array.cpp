//leetcode question

https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
class Solution {
public:
int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int unique = 1; 
    int n = nums.size();

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[unique] = nums[i];
            unique++;
        }
    }

    return unique;
}
};