set<vector<int>>st;
void solve(vector<int>v, vector<int>tmp, int id,int len){
    
    
    if(tmp.size()>=len){
      //  cout<<sum<<endl;
        sort(tmp.begin(),tmp.end());
        st.insert(tmp);
        return;
    }
    
    for(int i=id;i<v.size();i++){
        
        tmp.push_back(v[i]);
        
        solve(v,tmp,i+1,len);
        tmp.pop_back();
    }
         
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int>>ans;
    if(B>A)return ans;
    vector<int>v,tmp;
    st.clear();
    
    for(int i=1;i<=A;i++)v.push_back(i);
    solve(v,tmp,0,B);
    for(auto it:st){
        ans.push_back(it);
    }
    return ans;
    
}
