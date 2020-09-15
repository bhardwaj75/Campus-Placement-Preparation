//https://leetcode.com/problems/decode-string/submissions/
class Solution {
public:
    bool isNumber(char ch){
        string num ="0123456789";
        for(auto it : num){
            if(it==ch)return 1;
        }
        return 0;
    }
    vector<string>ans;
    int ct = 0;
    string decodeString(string s) {
        
       stack<string>ch;
        stack<int>num;
        string tmp="";
        int numb = 0;
        for(int i=0;i<s.size(); i++){
            
            if(s[i]!=']' && s[i]!='[' and !isNumber(s[i])){
                tmp+=s[i];
                continue;
            }
          
            else if(isNumber(s[i])){
                numb = numb*10 + (s[i]-'0');
                continue;
            }
            
            else if(s[i]=='['){
                
                if(numb>0)
                    num.push(numb);
                    ch.push(tmp);
                    
                numb=0;
                tmp="";
                ct++;
              
            }
       
            
            else if(s[i]==']'){
                        string tmp1 = tmp;
                
                for(int i = 0; i < num.top()-1; ++i) {
                    tmp += tmp1;
                }
                cout<<"tmp "<<tmp<<endl;
                tmp = ch.top() + tmp;
                cout<<"tmp "<<tmp<< " ch.top()"<<ch.top()<<endl;
                ch.pop(); num.pop();
            }
            
            
        }
        
        return tmp;
        
    }
};
