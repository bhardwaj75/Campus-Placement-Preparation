/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data="";
        
        if(!root)return data;
        queue<TreeNode*>que;
        que.push(root);
        
        while(!que.empty()){
            TreeNode*curr = que.front();
            que.pop();
            
            if(curr==NULL){
                data+="#,";
            } else {
                data+=to_string(curr->val)+",";
            }
            
            if(curr){
                que.push(curr->left);
                que.push(curr->right);
            }
            
        }
        cout<<data<<endl;
        return data;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode*root =NULL;
        
        if(data.size()<1)return root;
        
        stringstream s(data);
        string str;
        getline(s,str,',');
        
        queue<TreeNode*>que;
        cout<<str<<endl;
        root = new TreeNode(stoi(str));
        que.push(root);
        
        while(!que.empty()){
            
            TreeNode*node = que.front();
            que.pop();
             getline(s,str,',');
            
            if(str=="#"){
                node->left=NULL;
            } else {
                 node->left = new TreeNode(stoi(str));
                que.push(node->left);
            }
            
            getline(s,str,',');
            
            if(str=="#"){
                node->right=NULL;
            } else {
                 node->right = new TreeNode(stoi(str));
                que.push(node->right);
            }
            
            
            
        }
        return root;
       
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
