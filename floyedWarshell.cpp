class floydWarshell
{
public:

	int n;//Number of vertices
	vector<vector<int>>dp(n+1);
	floydWarshell(){

		 for(int i = 1;i<=n;i++){
		 	dp[i][i]=0;
		 }
	}

	void floydWarshellAlgo(){

		for(int k = 1; k<=n; k++)
			for(int i = 1; i<=n; i++)
				for(int j=1; j<=n; j++){

					if(dp[i][k]==INT_MAX or dp[k][j]==INT_MAX)continue;


					dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
				}


	}

	
};
