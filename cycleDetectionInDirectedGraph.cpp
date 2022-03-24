#include <bits/stdc++.h>
using namespace std;
std::vector<int> graph[100];

stack<int>topo;
bool dfs(vector<int>& vis, int u, int parent,vector<int>& dfsvis){

	vis[u] = 1;
	dfsvis[u]=1;
	for(int i=0; i<graph[u].size();i++){

		if(!vis[graph[u][i]]){

			if(dfs(vis,graph[u][i],u,dfsvis)) return true;
		} else if(dfsvis[graph[u][i]]) {
				return true;
		}


	}
	dfsvis[u]=0;
	return false;



}

int main(){

	int nodes;
	int edges;

   cin>>nodes>>edges;

   for(int i =0 ;i <edges; i++){
   	int u,v;
   	cin>>u>>v;
   	graph[u].push_back(v);
   	// graph[v].push_back(u);
   }

   std::vector<int> vis(nodes+1,0);
    std::vector<int> dfsvis(nodes+1,0);
   bool cycle = false;
   for (int i = 0; i <= nodes; ++i)
   {
   	  if(!vis[i]){
   	  	if(dfs(vis,i,-1,dfsvis)){
   	  		cout<<"Cycle \n";
   	  		cycle=true;
   	  		break;
   	  	}
   	  }
   }
   if(!cycle)cout<<"No cycle\n";
 
}
