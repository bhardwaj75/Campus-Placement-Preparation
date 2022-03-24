#include <bits/stdc++.h>
using namespace std;
std::vector<int> graph[100];

stack<int>topo;
bool dfs(vector<int>& vis, int u, int parent){

	vis[u] = 1;

	for(int i=0; i<graph[u].size();i++){

		if(!vis[graph[u][i]]){

			if(dfs(vis,graph[u][i],u)) return true;
		} else if(parent!=graph[u][i]) {
				return true;
		}


	}

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
   	graph[v].push_back(u);
   }

   std::vector<int> vis(nodes+1,0);
   bool cycle = false;
   for (int i = 0; i <= nodes; ++i)
   {
   	  if(!vis[i]){
   	  	if(dfs(vis,i,-1)){
   	  		cout<<"Cycle \n";
   	  		cycle=true;
   	  		break;
   	  	}
   	  }
   }
   if(!cycle)cout<<"No cycle\n";
 
}
