#include <bits/stdc++.h>
using namespace std;

int main() {



	int n,q;
	cin>>n>>q;

	long long arr[n+1];
	long long prefix_sum[n+2];


    for(int i=0;i<n+1;i++)prefix_sum[i]=0;


	std::vector<long long > v;


	for(int i=0;i<n;i++) {

		long long val;
		cin>>val;
		v.push_back(val);
	}
	sort(v.rbegin(), v.rend());
   

	long long sum = 0;

	while(q--) {

		int l,r;
		cin>>l>>r;

		prefix_sum[l]++;
		prefix_sum[r+1]--;
	}


	long long val = 0;

	priority_queue<long long>pq;
	for(int i=0;i<n;i++){
		val+=prefix_sum[i+1];
		prefix_sum[i+1] = val;
		pq.push(prefix_sum[i+1]);
	}

	int i = 0;
	   while(!pq.empty()) {

	   	long long value = pq.top();
	   	pq.pop();
		sum+=(value*v[i++]);
	}
	cout<<sum<<endl;

	return 0;
}
