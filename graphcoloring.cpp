#include <bits/stdc++.h>
using namespace std;
std::vector<int> graph[100];

stack<int>topo;
bool dfs(vector<int>& color, int u){

   if(color[u]==-1){
      color[u]=1;
   }

	for(auto it : graph[u]){
   
      if(color[it]==-1){
         color[it] = 1 - color[u];
         if(!dfs(color,it)) return false;

      } else if(color[it]==color[u]){
         return false;
      }

		
	}

   return true;


}

int main(){

	int nodes;
	int edges;

   cin>>nodes>>edges;

   for(int i =0 ;i <edges; i++){
   	int u,v;
   	cin>>u>>v;
   	graph[u].push_back(v);
   }

   std::vector<int> color(nodes+1,-1);

   int is_coloring_possible = true;

   for (int i = 0; i <= nodes; ++i)
   {
   	  if(color[i]==-1){
   	  	if(!dfs(color,i)){
            is_coloring_possible = false;
            break;
         }
   	  }
   }
   
   if(!is_coloring_possible)cout<<"Not possible\n";
   else {
      for(auto it: color){
         cout<<it<<" ";
      }
   }

}
