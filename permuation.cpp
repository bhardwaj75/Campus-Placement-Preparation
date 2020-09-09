#include<bits/stdc++.h>
using namespace std;

void permuation(string s, int index, string tmp){
    

	if(tmp.size() == s.size())
	{
		cout<<tmp<<endl;
		return;
	}

	tmp+=s[index];

	for(int i =0; i<tmp.size(); i++){
		swap(tmp[i],tmp[tmp.size()-1]);
		permuation(s,index+1, tmp);
		swap(tmp[i],tmp[tmp.size()-1]);
	}
}
int main(){

   string s,t;
   cout<<"enter";
   cin>>s;
	permuation(s,0,t);
	cout<<"finish";
	return 0;
}
