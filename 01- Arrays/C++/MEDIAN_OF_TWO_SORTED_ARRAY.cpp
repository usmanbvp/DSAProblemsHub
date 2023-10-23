class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        vector<int> ans;
        while(i<nums1.size() && j<nums2.size()){
if(nums1[i]<nums2[j])
{
    ans.push_back(nums1[i]);
    i++;
}
else
{
    ans.push_back(nums2[j]);
  j++;
   }  
}
for(;i<nums1.size();i++)
{
    ans.push_back(nums1[i]);
}
for(;j<nums2.size();j++)
{
    ans.push_back(nums2[j]);
}
        

        double median;
        int size=ans.size();
        if(size%2==0){
            median=(double)(ans[size/2]+ans[size/2-1])/2;
        }
        else{
            median=ans[size/2];
        }
        return median;
    }
    
};
