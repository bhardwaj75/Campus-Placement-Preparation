#include <bits/stdc++.h>
using namespace std;
void buildTree(vector<int> arr,vector<int> &tree, int start, int end, int treeNode){

	// for(auto it : arr){
	// 	cout<<it<<endl;
	// }

	// cout<<start<<" "<<end<<" "<<endl;
	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}

	int mid = (start+end)/2;

	buildTree(arr,tree, start, mid, 2*treeNode);
	buildTree(arr,tree, mid+1, end, 2*treeNode+1);

	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode +1];

}


int main(){

	std::vector<int> arr = {1,2,3,4,5};
	std::vector<int> tree(11,-1);

	buildTree(arr,tree,0,4,1);

	for(int i=1;i<10;i++){
		cout<<tree[i]<<endl;
	}
}
