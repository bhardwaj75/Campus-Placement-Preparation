#include <bits/stdc++.h>
using namespace std;
struct node {
      char data;
       char nkey;
       bool already_deleted;
      node *left;
      node *right;
  };

map<char,struct node*>Index;
struct node *dh;
struct node *dt;;


void initialize(void) {
            dh= new node;
            dt = new node;
            dh->data='@';
            dt->data='@';
            dh->right = dt;
            dt->left=dh;
            
    
}
    
char get(void) {
  

  struct node * run = dh->right;

  // while(run!=dt){
  //   cout<<run->nkey<<" ";
  //   run=run->right;
  // }
  // cout<<endl;


  return dh->right->data;
  
}
    
void put(char key, int value) {

                     int f=0;
                     if(Index.find(key)==Index.end())
                         f=1;
                     	if(!f){
                        
      		            struct node *tmp1 = Index[key];

                      if(tmp1->already_deleted)return;

                      tmp1->already_deleted=1;
                      Index[key]=tmp1;
          
            tmp1->left->right = tmp1->right;
            tmp1->right->left = tmp1->left;
      	}
          else {
          struct node *tmp = new node;
          tmp->data = value;
          tmp->nkey = key;
      	Index[key]=tmp;

      	tmp->left = dt->left;
          dt->left->right = tmp;

          tmp->right = dt;
          dt->left=tmp;
           
          }

}

int main() {

  int t;
  cin>>t;
  while(t--) {
        
        Index.clear();
        int n;
        cin>>n;
        initialize();
    
        for(int i=0;i<n;i++){


            char inp;
            cin>>inp;
          put(inp,inp);
          char ans = get();

          if(ans=='@')
            cout<<-1<<" ";
          else
          cout<<ans<<" ";
        }

        cout<<endl;



  }

}
