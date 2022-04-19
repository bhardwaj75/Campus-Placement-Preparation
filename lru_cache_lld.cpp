class LRUCache {
public:

    struct Node {
        Node *left;
        Node *right;
        int key;
        int val;

        void setKey(int _key){
            key = _key;
        }
        void setVal(int _val){
            val = _val;
        }

        int getVal(){
           return val;
        }

        int  getKey(){
            return key;
        }

    };

    map<int,Node*>nodeMp;


    Node * head = NULL;
    Node * tail = NULL;
    int cacheCapacity;

    void createDummyNodes(){
        head = new Node;
        tail = new Node;

        head->setKey(-1);
        head->setVal(0);

        tail->setKey(-1);
        tail->setVal(0);

        head->right = tail;
        tail->left = head;


    }


    LRUCache(int capacity) {
      cacheCapacity = capacity;
      createDummyNodes();


    }
    
   
    void adjustNode(int key){
          Node * node = nodeMp[key];

           Node * nodeLeft =  node->left;
           Node * nodeRight = node->right;
        
           nodeLeft->right = nodeRight;
           nodeRight->left = nodeLeft;
           

        
            Node * tailLeft = tail->left;

            tailLeft->right = node;
            tail->left = node;
            node->left = tailLeft;
            node->right = tail;
        
            nodeMp[key] = node;
    }

    int get(int key) {


        if(nodeMp.find(key)!=nodeMp.end()){

            int value = nodeMp[key]->getVal();
            adjustNode(key);
            
            
            return value;

        }

        return -1;

    }

    bool ifKeyExist(int key){

        if(nodeMp.find(key)!=nodeMp.end()){
            return true;
        }
        return false;
    }

    bool isCapacityFull(){

        return nodeMp.size()>=cacheCapacity;

    }

    void insertNode(int key, int value){
        Node * node = new Node;
        node->setVal(value);
        node->setKey(key);

        tail->left->right = node;
        node->left = tail->left;
        tail->left = node;
        node->right = tail;
        
        nodeMp[key] = node;
    }
    void evictKey(){
        Node * node = nodeMp[head->right->getKey()];

        if(nodeMp.find(head->right->getKey())!=nodeMp.end()){
           
        }
        
        head->right = node->right;
        node->right->left = head;
        

        nodeMp.erase(node->getKey());

    }
    void put(int key, int value) {


        if(ifKeyExist(key)){
            nodeMp[key]->setVal(value);

            adjustNode(key);


        } else if(isCapacityFull()){
            evictKey();
            insertNode(key,value);
        } else {
            insertNode(key,value);

        }


    }
};
