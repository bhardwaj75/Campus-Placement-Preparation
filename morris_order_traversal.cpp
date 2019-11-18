/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inOrderpredecessor(TreeNode* pre, TreeNode* current) {
        
            while (pre->right != NULL && pre->right != current) 
                pre = pre->right;
        return pre;
                
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        TreeNode* current = root;
        while(current!=NULL) {
            if(current->left==NULL){
                ans.push_back(current->val); 
                current = current->right;
            }
            
            else {
                
                 TreeNode* pred = inOrderpredecessor(current->left, current);
                 
                 if(pred->right==NULL){
                     pred->right = current;
                     current = current->left;
                 }
                else {
                    pred->right=NULL;
                     ans.push_back(current->val); 
                    current = current->right;
                }
                    
            }      
            
        }
        return ans;
    }
};
