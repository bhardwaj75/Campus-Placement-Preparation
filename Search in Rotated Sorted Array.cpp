class Solution {
public:
    
    int find_index(vector<int>& nums, int l, int r, int target) {
       
         int mid2 = (l+r)/2;
        
        if(nums[mid2]==target){
            return mid2;
        }
        
        if(l > r){
            return -1;
        }
        while(l<=r){
            
            if(l==r){
                if(nums[l]!=target)return -1;
            }
            
            int mid = (l+r)/2;
            
            if ( nums[mid]==target){
                return mid;
            }
            if(nums[l]>nums[mid]){
                
                if(target>=nums[mid] and target<=nums[r]){
                    l = mid;
                } else {
                    r = mid-1;
                }
            }
            else if(nums[l]<nums[mid]){
                
                if(target>=nums[l] and target<=nums[mid]){
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            
            else if (nums[l]==nums[mid]){
               int result = find_index(nums,l,mid,target);
                
               if(result ==-1){
               result = find_index(nums, mid+1, r,target);
               }
                return result;
                
            }
           
            
        }
        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        
        if(nums.size()<1)return -1;
        return find_index(nums,0,nums.size()-1,target);
    }
};
