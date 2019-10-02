#include <bits/stdc++.h>
using namespace std;

/*



11110111101111001111


1111 0 1111 0 1111 00 1111
seg4   seg3	  seg2	  seg1

*/
int main(){

	int x;
	cin>>x;

	int prevlen=0;
	int curlen=0;
	int mx = 1;
	while(x!=0){


		if((x&1)==1){
			curlen++;
		}
		else {


				//mx=max(curlen+prevlen+1,mx);
             if((x&2)==0){
             	prevlen=0;
             	curlen=0;
             }
             else {
             	prevlen =curlen;
             	curlen=0;
             }

		}
		mx=max(curlen+prevlen+1,mx);
		x>>=1;
	}

	cout<<mx<<endl;
	return 0;
}
