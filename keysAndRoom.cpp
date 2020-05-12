/***https://leetcode.com/problems/keys-and-rooms/***/

class Solution {
public:
    
    void dfs(int u,vector<vector<int>>& g, vector<int>&vis ){
        
        if(vis[u])return;
        vis[u]=1;
        
        for(auto it: g[u]){
            if(!vis[it])dfs(it,g,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
           int n = rooms.size();
           vector<vector<int>>g(n);
        
           for(int i=0;i<n;i++){
               for(int j=0;j<rooms[i].size(); j++){
                   g[i].push_back(rooms[i][j]);
               }
           }
        
        int c =0;
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++){
            
            if(!vis[i]){
                dfs(i,g,vis);
                c++;
            }
        }
        
        return c==1;
    }
};
