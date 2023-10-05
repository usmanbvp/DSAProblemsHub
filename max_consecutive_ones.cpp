// leetcode question

https://leetcode.com/problems/max-consecutive-ones/description/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int maximum=0;
       int now=0;
       for(int i=0;i<nums.size();i++){
           if(nums[i]==1){
               now=now+1;
               maximum=max(maximum,now);
           }
           else{
               now=0;
           }
       }
    return maximum;
    }
};
 



    