/*https://leetcode.com/problems/minimum-window-substring/*/
class Solution {
public:
    
    bool all_match(unordered_map<char,int>&text_hash, unordered_map<char,int>&pattern_hash){
        
       for(auto it : pattern_hash){
           
           
           if(text_hash[it.first]<pattern_hash[it.first]){
                return 0;
           }
              
       }
     
        return 1;
        
    }
    string minWindow(string s, string t) {
        
        unordered_map<char,int>text_hash;
        unordered_map<char,int>pattern_hash;
        int start = 0;
        int end = -1;
        int mx_size = INT_MAX;
        int j=0;
        int i = 0;
        string ans="";
        
       
        for(auto it: t){
            pattern_hash[it]++;
         
        }
         
            while(j<s.size()){
             
                text_hash[s[j]]++;
                
                while(all_match(text_hash, pattern_hash)){
                   
                     int sz = j-i+1;
                     if(sz<mx_size){
                            mx_size = sz;
                            start = i;
                            end = j;
                     }
                     
                    
                    text_hash[s[i++]]--;
                    
                }
                
                j++;
            }
        
            
        for(int i=start;i<=end;i++){
            ans+=s[i];
        }
        
        return ans;
        
        
        
    }
};
