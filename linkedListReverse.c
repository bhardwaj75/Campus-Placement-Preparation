/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        
        ListNode*prev = NULL;
        ListNode*cur = head;
        ListNode*Next = head;
        while(cur!=NULL){
            Next = cur->next;
            cur->next=prev;
            prev = cur;
            cur=Next;
            
        }
        return prev;
        
    }
};


//Recursiver
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
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL)return NULL;
        if(head->next ==NULL)return head;
        
        ListNode *tmp = reverseList(head->next);
        
        head->next->next =head;
        head->next=NULL;
        return tmp;
        
        
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode*  rev(ListNode* curr, ListNode* prev){
        
        if(!curr){
            return prev;
        }
        ListNode* tmp = curr->next;
        curr->next=prev;
        return rev(tmp, curr);
        
    }
    ListNode* reverseList(ListNode* head) {
       
        return rev(head, nullptr);
    }
};
