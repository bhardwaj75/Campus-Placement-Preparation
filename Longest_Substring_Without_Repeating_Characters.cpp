/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0;
        map<char,int>char_freq;
        deque<int>dq;
        
        for(int i=0;i<s.size(); i++){
            
            if(char_freq.find(s[i])!=char_freq.end()){
                mx = max(mx, i-dq.front());
                while(!dq.empty() and s[dq.front()]!=s[i]){
                    char_freq.erase(s[dq.front()]);
                    dq.pop_front();
                }
               dq.push_back(i);
                
                dq.pop_front();
                char_freq[s[i]]--;
            } else {
                char_freq[s[i]]++;
                dq.push_back(i);
                mx = max(mx, i-dq.front()+1);
                
            }
            
            
        }
        return mx;
    }
};
