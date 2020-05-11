/****
https://leetcode.com/problems/regions-cut-by-slashes/
****/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int R[4] = { -1, 0, 0, 1};
	int C[4] = {0, -1, 1, 0};

	bool isValidMove(int r, int c, int x, int y, vector<vector<int>>&ngrid) {

		if (x < r && y<c and x >= 0 and y >= 0 and ngrid[x][y] == 0)return 1;
		return 0;


	}
	void dfs(vector<vector<int>>&ngrid, vector<vector<int>>&vis, int x, int y) {

		vis[x][y] = 1;
		int r = ngrid.size();
		int c = ngrid[0].size();
		for (int i = 0; i < 4; i++) {

			if (isValidMove(r, c, x + R[i], y + C[i], ngrid)) {
				if (!vis[x + R[i]][y + C[i]]) {
					dfs(ngrid, vis, x + R[i], y + C[i]);
				}
			}
		}

	}
	int regionsBySlashes(vector<string>& grid) {

		int r = grid.size() * 3;
		int c = grid[0].size() * 3;
		vector<vector<int>>ngrid(r, vector<int>(c, 0));
		vector<vector<int>>vis(r, vector<int>(c, 0));

		for (int i = 0; i < grid.size(); i++) {

			for (int j = 0; j < grid.size(); j++) {
				// cout<<grid[i][j]<<endl;
				if (grid[i][j] == '/') {
					ngrid[3 * i][3 * j + 2] = 1;
					ngrid[3 * i + 1][3 * j + 1] = 1;
					ngrid[3 * i + 2][3 * j] = 1;

				}
				if (grid[i][j] == '\\') {
					ngrid[3 * i ][3 * j] = 1;
					ngrid[3 * i + 1][3 * j + 1] = 1;
					ngrid[3 * i + 2][3 * j + 2] = 1;

				}

			}
		}
		int count = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << ngrid[i][j] << "";
				if (!vis[i][j] and ngrid[i][j] == 0) {
					// cout << i << " " << j << endl;
					dfs(ngrid, vis, i, j);
					count++;
				}
			}
			cout << endl;
		}
		return count;
	}
};
int main(int argc, char const *argv[])
{

	Solution obj;

	vector<string>grid = {"/\\", "\\/"};
	cout << obj.regionsBySlashes(grid);

	return 0;
}
