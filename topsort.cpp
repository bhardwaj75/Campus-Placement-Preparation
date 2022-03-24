#include <bits/stdc++.h>
using namespace std;
std::vector<int> graph[100];

stack<int>topo;
void dfs(vector<int>& vis, int u){

	vis[u] = 1;

	for(int i=0; i<graph[u].size();i++){

		if(!vis[graph[u][i]])
			dfs(vis,graph[u][i]);
	}
	cout<<u<<endl;
	topo.push(u);

}

int main(){

	int nodes;
	int edges;

   cin>>nodes>>edges;

   for(int i =0 ;i <edges; i++){
   	int u,v;
   	cin>>u>>v;
   	graph[v].push_back(u);
   }

   std::vector<int> vis(nodes+1,0);

   for (int i = 1; i <= nodes; ++i)
   {
   	  if(!vis[i]){
   	  	dfs(vis,i);
   	  }
   }
   std::vector<int> ans;
   while(!topo.empty()){
   	ans.push_back(topo.top());
   	topo.pop();
   }
   for(auto it : ans){
   	cout<<it<<" ";
   }

}
