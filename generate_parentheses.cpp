/****

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

****/


class Solution {
public:
    
    bool is_open_and_close_braces_count_same(string s){
        
        int op_count = 0;
        int close_count = 0;
        
          for(auto it : s) {
            if(it =='(')
                op_count++;
             else
                 close_count++;
        }
        
        return op_count == close_count;
    }
    int count_opening_braces(string s){
        
        int count = 0;
        for(auto it : s) {
            if(it =='(')
                count++;
        }
        return count;
    }
    void gen(string s, int n, vector<string>&perm){
       
        if(s.size() == 2*n) {
             cout<<s<<endl;
            perm.push_back(s);
            return ;
        }
        
        if(count_opening_braces(s) == n){
            s +=')';
            gen(s,n,perm);
        }
        else if(s[s.size()-1]==')' and is_open_and_close_braces_count_same(s)){
            
            s +='(';
            gen(s,n,perm);
                
        }
        else {
            
             s +='(';
            gen(s,n,perm);
            s[s.size()-1] = ')';
            gen(s,n,perm);
            
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string>perm;
        gen("(", n, perm);
        return perm;
        
    }
};
