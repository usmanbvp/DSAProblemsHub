// Number of Unequal Triplets in Array

class Solution {
    public int unequalTriplets(int[] nums) {
        int count = 0;
        int n = nums.length;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = i + 2; k < n; k++) {
                    if (i < j && j < k) {
                        if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k])
                            count++;
                    }
                }
            }
        }
        return count;
    }
}