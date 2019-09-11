/*Algorithm :


Maintain double linked list with dumy head and dummy tail and hash map for mapping key vs pointer location.

Double linked List structure:
   struct node {
      int data;
       int nkey;
      node *left;
      node *right;
  };

Lets say dh = dummy head node, dt = dummy tail

Intially it will be like.      |dh|--->|dt|

and capcity lets say 2.
      
Now put(1,2):                         
                |dh|<--->|1|<----->|dt|                            map ={(1,pointer1)}
Now put (2,3):  |dh|<--->|2|<---->|1|<----->|dt|                   map = {(1,pointer1),(2,pointer2)}

Now get (1):     |dh|<--->|1|<---->|2|<----->|dt|     

Now put(3,5): but capacity is already full then it will delete lru i.e last node befor dt
                
                |dh|<--->|3|<---->|1|<----->|dt|                   map = {(1,pointer1),(3,pointer3)}


*/




class LRUCache {
    
   struct node {
      int data;
       int nkey;
      node *left;
      node *right;
  };
    
;
public:

    map<int,struct node*>index;
    struct node *dh= new node;
    struct node *dt = new node;
    int c;
    LRUCache(int capacity) {
        
                dh->data=-2;
                dt->data=-3;
                dh->right = dt;
                dt->left=dh;
                c= capacity;
                
        
    }
    
    int get(int key) {
        
        int key1 = key;

        //If key is not there return -1
        if(index.find(key1)==index.end())return -1;
        struct node *tmp2 = index[key1];


        //If key found update it in the start of LL and delete it from it's actual position
        struct node *tmp3 = new node;
        int ans = tmp2->data;
        tmp3->nkey=tmp2->nkey;

        tmp2->left->right = tmp2->right;
        tmp2->right->left = tmp2->left;


        tmp3->data = ans;
        index[key]=tmp3;

        tmp3->right = dh->right;
        dh->right->left = tmp3;

        dh->right = tmp3;
        tmp3->left=dh;
        return ans;
        
    }
    
    void put(int key, int value) {

                            int f=0;
                           if(index.find(key)==index.end())
                               f=1;
                         
                              cout<<"map size() "<<index.size()<<" "<<" key "<<key<<" f "<<f<<endl;

                              //If capacity is exceeded delete lru element
                           	if(f and index.size()>=c){
                                 
                                  cout<<"delete lru"<<dt->left->nkey<<endl;
                               int id = dt->left->nkey;
                                index.erase(id);
            		dt->left->left->right=dt;
            		dt->left = dt->left->left;

            	}
                if(f==1) {

                //Inster new element
                cout<<"Insert "<<key<<endl;
                struct node *tmp = new node;
                tmp->data = value;
                tmp->nkey = key;
            	index[key]=tmp;

            	tmp->right = dh->right;
                dh->right->left = tmp;
                 
                dh->right = tmp;
                tmp->left=dh;
                } else {

                  //Update the value of existing key
					struct node *tmp1 = index[key];
                       cout<<"update key "<<key<<endl;
                       
                      index.erase(key);
					  tmp1->left->right = tmp1->right;
					  tmp1->right->left = tmp1->left;


				struct node *tmp = new node;
                tmp->data = value;
                    tmp->nkey = key;
            	index[key]=tmp;
               
               	tmp->right = dh->right;
                dh->right->left = tmp;
                 
                dh->right = tmp;
                tmp->left=dh;
                 cout<<"map size() after update "<<index.size()<<" "<<"key "<<key<<" f "<<f<<endl;


                }
 
    }
};

