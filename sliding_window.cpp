#include <bits/stdc++.h>


// 3 4 1 2 7 5 8
using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {

		int n = nums.size();
		deque<int>pq;
		std::vector<int> ans;
		std::vector<int> v = nums;
		int i;
		for(i=0;i<k;i++){


		if(pq.empty()){
		pq.push_back(i);
		}
		else {

			while(!pq.empty() && v[i]>v[pq.back()])
			 		pq.pop_back();
			pq.push_back(i);

		}	

		}
		ans.push_back(v[pq.front()]);
		// cout<<pq.front()<<endl;

		for(int j=i;j<n;j++){
		if(pq.empty()){
			pq.push_back(j);
		}
		else {
			 

			 while(!pq.empty() && j-pq.front()>=k){
		 			pq.pop_front();
		 	}

		 	if(pq.empty()){
		 		pq.push_back(j);
		 	}

		 	else {
				    int fval = pq.front();

			 		while(!pq.empty() && v[j]>v[pq.back()])
			 			pq.pop_back();
			 		pq.push_back(j);

				 
			}
		}

		// cout<<pq.front()<<endl;
		ans.push_back(v[pq.front()]);

		}

		return ans;

		}


int main(){

	
	int n,k;
	std::vector<int> v ;
	cin>>n>>k;
	int val;
	for(int i=0;i<n;i++){
		cin>>val;
		v.push_back(val);
	}

	vector<int> ans = maxSlidingWindow(v,k);

	for(auto it : ans){
		cout<<it<<endl;
	}

	return 0;
}
