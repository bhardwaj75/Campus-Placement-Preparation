//https://leetcode.com/problems/remove-invalid-parentheses/
class Solution {
public:
    int minimumRemoval(string s){
        stack<char>st;
        
        for(auto it: s){
            
            if(it==')'){
                
                if(!st.empty() and st.top()=='('){
                    st.pop();
                } else {
                    st.push(')');
                }
                
            } else if(it=='('){
                st.push('(');
            }
        }
        
        return st.size();
    }
    
    
    void generatePar(string s, int mnRemoval,  unordered_map<string,int>&ans,unordered_map<string,int>&hash){
       
      
        if(mnRemoval<=0){
            
            
            if(minimumRemoval(s)==0){
              
                if(ans.find(s)==ans.end())
                    ans[s] = 1;
            }
            return;
        }
        
        for(int i = 0; i<s.size(); i++){
            
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            if(hash.find(left+right)==hash.end()){
                generatePar(left+right,mnRemoval-1,ans,hash);
                hash[left+right] = 1;
            }
            
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        
        unordered_map<string,int>ans,hash;
        int mnRemoval = minimumRemoval(s);
    
        if(mnRemoval==s.size())return {""};
      
        
        generatePar(s,mnRemoval,ans,hash);
        vector<string>fans;
        
        for(auto it: ans){
           
            fans.push_back(it.first);
        }
        return fans;
        
    }
};
