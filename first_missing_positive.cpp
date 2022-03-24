/*Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        
        int j = 0;
        int len = nums.size();
        
        
        while(j<len){
            
            
            while(nums[j]>0 and nums[j]-1<len and nums[j]!=j+1 and nums[j]!=nums[nums[j]-1]){
                
                swap(nums[j],nums[nums[j]-1]);
                
                
            }
            
            j++;
            
        }
        
        int ans = -1;
        
        for(int i = 0; i<len; i++){
            if(nums[i]!=i+1){
                ans = i+1;
                break;
            }
        }
        
        return ans==-1?len+1:ans;
    }
};
