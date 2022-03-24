#include <bits/stdc++.h>
using namespace std;

struct Node
{
	Node * child[26];
	bool Last;

	bool contains(char ch){

		return this->child[ch-'a']!=NULL;
	}

	void addNode(char ch){

		this->child[ch-'a'] = new Node();
	}

	Node* getNext(char ch){

		return this->child[ch-'a'];
	}

	void setLast(){
		this->Last = true;
	}

	bool isLast(){

		return this->Last;
	}

	
};

class trie2
{
public:
	
	Node * root = new Node();
	

	void insert(string word){
		Node * node = root;

		for(int i = 0; i<word.size(); i++){

			if(!node->contains(word[i])){

				node->addNode(word[i]);
			}
			node = node->getNext(word[i]);
		}
		node->setLast();

	}


	bool search(string word){
		Node * node = root;
		for(int i = 0; i<word.size(); i++){

			if(!node->contains(word[i])){

				cout<<word[i]<<endl;
				return false;
			}
			node = node->getNext(word[i]);
		}

		if(!node->isLast())return false;

		return true;

	}


	
};

int main(){

	trie2 *trie = new trie2();

	string s;
	cin>>s;

	trie->insert(s);
	int q;
	cin>>q;

	while(q-->0){

		string pat;
		cin>>pat;

		cout<<(trie->search(pat))<<endl;
	}



}
