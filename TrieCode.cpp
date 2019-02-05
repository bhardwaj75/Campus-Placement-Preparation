#include<iostream>
using namespace std;

struct trie{
    struct trie *child[26];
    bool is_last_node;
};
struct trie *get_node(void) {
    
    struct trie *root = new trie;
    root->is_last_node = 0;
    for(int i=0;i<26;i++)
        root->child[i] = NULL;
}

void insert(struct trie *root, string word) {
    
    struct trie *temp = root;
    for(int i=0;i<word.size();i++){
    if(!temp->child[word[i]-'a'])
       temp->child[word[i] -'a']= get_node();
       
       temp =  temp->child[word[i] -'a'];
    }
    
    temp->is_last_node = 1;
    
}
bool search(struct trie*root, string key) {
    
    struct trie * p = root;
    
    for(int i=0;i<key.size();i++){
        
        if(!p->child[key[i]-'a']) return 0;
        p = p->child[key[i]-'a'];
    }
    return (p!=NULL & p->is_last_node);
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    struct trie * root = get_node();
	    for(int i=0;i<n;i++){
	        string s;
	        cin>>s;
	        insert(root, s);
	    }
	    string ss;
	    cin>>ss;
	    
	    cout<<search(root, ss)<<endl;
	    
	}
	
}
