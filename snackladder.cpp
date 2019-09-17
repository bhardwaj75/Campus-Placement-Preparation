//
// Created by Diwakar on 9/17/19.
//
#include "bits/stdc++.h"
using namespace std;
int main() {

    int testcases;
    cin>>testcases;
    while (testcases--) {
        int n;
        map<int,int>mp;
        map<int,int>val;
        map<int,int>vis;

        queue<pair<int,int>>q;
        cin>>n;
        for(int i=1;i<=n;i++) {
            int from,to;
            cin>>from>>to;
            mp[from] = to;
        }
        q.push(make_pair(1,0));
        int ans;
        while(!q.empty()) {

            pair<int,int>z= q.front();

            int a = z.first;
            int b = z.second;

           // cout<<"a "<<a<<" b"<<b<<endl;
            q.pop();

            if(a==30) {
                ans = b;
           // cout<<" a: "<<a<<" b: "<<b<<endl;
            }
            for(int i=1;i<=6;i++) {
               

                       if(vis.find(a+i)!=vis.end()){
                           // cout<<"already visited"<<" "<<a+i<<endl;
                            continue;
                        }
                     
                    if(a+i>30)
                        continue;
           // cout<<"i :"<< i<<" a+i: "<<a+i<<" b: "<<b+1<<endl;
                    vis[a+i]=1;
                if(mp.find(a+i)!=mp.end()){
                    q.push(make_pair(mp[a+i],b+1));
                    
                }
                else {
                    q.push(make_pair(a+i, b+1));
                }
            }


        }
        cout<<ans<<endl;



    }

    return 0;
}

