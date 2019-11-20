/****
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water
and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3



****/

#include <bits/stdc++.h>
using namespace std;

int vis[1001][1001];
vector<vector<char> >v;
void dfs(int x, int y, int n, int m) {
	if(vis[x][y])return;


	vis[x][y] = 1;

	if(x-1>=0){
		if(v[x-1][y]=='1'){
			dfs(x-1,y,n,m);
		}
	}

	if(x+1<n){
		if(v[x+1][y]=='1' ){
			dfs(x+1,y,n,m);
		}
	}

	if(y-1>=0){
		if(v[x][y-1]=='1'){
			dfs(x,y-1,n,m);
		}
	}

	if(y+1<m){
		if(v[x][y+1]=='1'){
			dfs(x,y+1,n,m);
		}
	}


}

int numIslands(vector<vector<char>>& grid) {

	int n = grid.size();
	int m = grid[0].size();

	int counter = 0;
	for(int i=0;i<n; i++)
		for(int j= 0; j<grid[i].size(); j++){

			  if(!vis[i][j] and v[i][j]=='1'){
			  	counter++;
			  	dfs(i,j,n,m);
			  }
		}

return counter;
        
}


int main() {


	int n,m;
	cin>>n>>m;

	
	for(int i=0;i<n;i++){

		std::vector<char> tmp;

		for(int j=0;j<m;j++){
			char c;
			cin>>c;
			tmp.push_back(c);
		}
		v.push_back(tmp);
	}

	cout<<numIslands(v);
}
