//leetcode solution


https://leetcode.com/problems/move-zeroes/description/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i,j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[j],nums[i]);
                j++;
            }
        }
        // vector<int> zero;
        // vector<int> other;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0){
        //         zero.push_back(0);
        //     }
        //     else if(nums[i]!=0){
        //         other.push_back(nums[i]);
        //     }
        // }
        // vector<int> finall;
        // finall.push_back(other);
        // finall.push_back(zero);
        // return finall;

    }
};\