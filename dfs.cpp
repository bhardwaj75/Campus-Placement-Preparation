class dfs
{
	vector<int> vis;
	vector<vector<int>>graph;

public:
	dfs(int n){
		vis.resize(n);
		graph.resize(n);
	}

	void addNode(int u, int v){
		graph[u].push_back(v);
	}

	void doDfs(int u){

		vis[u] = true;

		for(auto vertex : graph[u]){
			if(!vis[vertex]){
				dfs(vertex);
			}
		}
	}
	
};
