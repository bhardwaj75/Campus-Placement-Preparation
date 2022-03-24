class bfs
{
	vector<int> vis;
	queue<int>que;
	std::vector<vector<int> > graph;
public:
	bfs(int n){

		vis.resize(n);
		graph.resize(n);

	}

	void addNode(int u, int v){

		graph[u].push_back(v);
	}

	void doBfs(int u){


		que.push(u);
		vis[u] = true;

		while(!que.empty()){

			int v = que.top();
			que.pop();
			vis[v] = true;

			for(auto vertex : graph[u]){
				if(!vis[vertex])
             		que.push(vertex);
			}
		}
	}


	
};
