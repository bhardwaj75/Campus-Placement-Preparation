/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL || head->next==NULL)return head;
        ListNode*ans;
        ListNode* prev = head;
        ans = prev;
        ListNode* cur = head->next;
        
        while(cur!=NULL){
            
            if(cur->val==prev->val){
                cur=cur->next;
            }else {
                prev->next=cur;
                prev = cur;
                cur=cur->next;
            }
        }
        prev->next = NULL;
        return ans;
        
        
    }
};
