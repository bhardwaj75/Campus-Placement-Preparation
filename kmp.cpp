#include <bits/stdc++.h>

using namespace std;


//abcabd

void kmpSearch(vector<int>&lps,string pattern, string text){

  int n = text.size();
  int m = pattern.size();

  int i= 0;
  int j = 0;

  while(i < n){

  	if(pattern[j]==text[i]){
  		i++;
  		j++;
  	}

  	if(j==m){
  		cout<<"Patter found at index "<<i-j<<endl;
  		j = lps[j-1];
  	}
  	else if(i<n && pattern[j]!=text[i]){
  		if(j!=0){
  			j = lps[j-1];

  		} else {
  			i+=1;
  		}
  	}

  }

}
void calculateLpsArray(vector<int>&lps,string pattern){


	int i = 0;
	int j = 1;

	while(j<pattern.size()){


		if(pattern[i]==pattern[j]){

			i++;
			lps[j]= i;
			j++;
		} else {

			if(i!=0){
				i = lps[i-1];
			} else {
				lps[j] = 0;
				j++;
			}

		}

	}
}


int main(){


	string text;
	string pattern;
	cin>>text;
	cin>>pattern;

	vector<int>lps(pattern.size(),0);
	calculateLpsArray(lps,pattern);
	kmpSearch(lps,pattern,text);
}
