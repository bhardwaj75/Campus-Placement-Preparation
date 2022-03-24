#include <bits/stdc++.h>
using namespace std;


void forMap(){
	map<int,int>mp;
	mp[4]=1;
	mp[7]=1;
	mp[2]=1;
	mp[13]=1;
	mp[9]=1;


	auto it = mp.lower_bound(6);

	cout<<it->first<<endl;
}

void forSet(){


	set<int>st;
	st.insert(1);
	st.insert(6);
	st.insert(2);
	st.insert(3);
	st.insert(5);



	auto it = st.lower_bound(4);

	cout<<(*it)<<endl;
}

int main(){

	forSet();
	forMap();

}
