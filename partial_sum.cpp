//update range value by 1 only
#include <bits/stdc++.h>
using namespace std;

int main() {

	long long prefix_sum[n+2];
  
  for(int i=0;i<n+1;i++)prefix_sum[i]=0;

	while(q--) {

		int l,r;
		cin>>l>>r;

		prefix_sum[l]++;
		prefix_sum[r+1]--;
	}
	long long val = 0;
	for(int i=0;i<n;i++){
		val+=prefix_sum[i+1];
		prefix_sum[i+1] = val;
	}
	return 0;
}
