vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    
    int last_row = A.size()-1;
    int last_col = A[0].size()-1;
    int l =0,r=0;
    
    vector<int>ans;
    while(l<=last_row and r<=last_col) {
        
        for(int i=l;i<=last_col;i++){
            ans.push_back(A[l][i]);
        }
        l++;
         for(int j=l;j<=last_row;j++){
            ans.push_back(A[j][last_col]);
        }
        last_col--;
        
        if(last_row>=l){
            for(int k = last_col ;k>=r;k--){
                ans.push_back(A[last_row][k]);
            }
        }
        last_row--;
        
        if(last_col>=r){
             for(int m = last_row ;m>=l;m--){
                ans.push_back(A[m][r]);
            }
        }
        r++;
        
    }
    return ans;
}
