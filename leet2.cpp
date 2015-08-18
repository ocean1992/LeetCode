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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL ;
        ListNode* cur = NULL ;
        int ni = 0 ;
        while(l1 != NULL && l2!= NULL){
            int nv = l1->val+l2->val+ni ;
            ni = nv/10 ;
            nv = nv%10 ;
            ListNode* t = new ListNode(nv) ;
            if(head == NULL){
                head = t ;
            }else{
                cur->next =t ;
            }
            cur = t ;
            l1 = l1->next ;
            l2 = l2->next ;
        }
        ListNode* cc = l1 ;
        if(l1 == NULL)
            cc = l2 ;
        while(cc!=NULL){
            int nv = cc->val + ni ;
            ni = nv/10 ;
            nv = nv%10 ;
            ListNode *t = new ListNode(nv) ;
            cur->next = t ;
            cur = t ;
            cc = cc->next ;
        }
        if(ni>0){
            ListNode *t = new ListNode(ni) ;
            cur->next =t ;
            t = cur ;
        }
        return head ;
    }
};