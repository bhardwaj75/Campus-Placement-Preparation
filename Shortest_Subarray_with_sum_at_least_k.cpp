class Solution {
public:
    
    /*
      find:
        p[y]-p[x]>=K
      
      this is only possible if our P array in non decreasing order
    
            p1<p2<p3<p4.......<pn
    */
    int shortestSubarray(vector<int>& nums, int k) {
        
        deque<pair<int,int>>dq= {{-1, 0}};
        int shortest_len = INT_MAX;
        int prefix_sum = 0;
        for(int i =0 ;i <nums.size();i++){
            
            prefix_sum+=nums[i];
            
            while(dq.size() && prefix_sum-dq.front().second>=k){
                shortest_len = min(shortest_len,i-dq.front().first);
                dq.pop_front();
            }
            
             while(dq.size() && prefix_sum<=dq.back().second){
                dq.pop_back();
            }
            
            dq.push_back(make_pair(i,prefix_sum));
        }
        
        return shortest_len==INT_MAX?-1:shortest_len;
       
    }
};Shortest_Subarray_with_sum_at_least_k.cpp
