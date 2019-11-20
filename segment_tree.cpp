#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100000

int t[4*MAX_SIZE];
void init(){

	for(int i = 0; i<4*MAX_SIZE; i++)
			t[i] = 0;
}


void build(std::vector<int> a, int v, int tl, int tr) {

    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}


int sum(int x,int y,int id ,int l ,int r){// [x, y)
	if(x > r or l >  y)	return 0;// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)	// [l,r) is a subset of [x,y)
		return t[id];
	int mid = (l + r)/2;
	return sum(x, y, id * 2, l, mid) +
	       sum(x, y, id*2+1, mid+1, r) ;
}




int main() {



	int n;
	cin>>n;

	std::vector<int> v;
	int val;
	for(int i=0;i<n;i++) {
		cin>>val;
		v.push_back(val);
	}
	build(v,1,0,n-1);
	int q;
	cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<sum(x,y,1,0,n-1)<<endl;
	}
	



}



