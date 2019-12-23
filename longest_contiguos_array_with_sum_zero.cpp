vector<int> Solution::lszero(vector<int> &A) {
   
int n = A.size();
   vector<int>pos(n,0);
    vector<int>neg(n,0);

    vector<int>sum(n,0);
    map<int,vector<int>>mp;
     map<int,vector<int>>mp1;
    int pprev = 0;
    int nprev = 0;
    int psum = 0;
    for(int i=0;i<n;i++){
        
         psum+=A[i];
         sum[i]=(psum);

         mp[psum].push_back(i);
    }
    
    int mx = -1;
    int l =-1,r=-1;
    for(int i=0;i<n;i++){
        if(sum[i]==0){
            if(abs(-1-i)>mx){
            mx = abs(-1-i);
            l = -1;
            r = i;
        }
    }
}
   
    for(auto it : mp) {
        
        int x = it.second[0];
        int y = it.second[it.second.size()-1];

        if(abs(x-y)>=mx and it.second.size()>1){
            
            if( mx ==abs(x-y)){

                if(l>x) {
                l =x;
                r = y;
            }
                continue;
            }

            l =x;
            r = y;
            mx = abs(x-y);
        }
        
    }
    
    vector<int>ans;
    for(int i=l+1;i<=r;i++)ans.push_back(A[i]);
    return ans;
    
}
