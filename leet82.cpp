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
        if(head == NULL || head->next == NULL)
            return head ;
        ListNode* curr = head->next ;
        int nval = head->val ;
        ListNode* st = NULL ;
        ListNode* prev = head ;
        ListNode* pprev = NULL ;
        int state = 0 ;
        while(curr != NULL){
            if(curr->val == nval){
                if(state == 0){
                    st = pprev ;
                    state = 1 ;
                }
                if(curr->next == NULL){
                    if(st == NULL)
                        return NULL ;
                    else
                        st->next = NULL ;
                }
            }else{
                if(state == 1){
                    if(st == NULL)
                        head = curr ;
                    else
                        st->next  = curr ;
                    state = 0 ;
                    pprev = st ;
                }else{
                     if(pprev == NULL)
                        pprev = head ;
                    else
                        pprev = pprev->next ;
                }
                nval = curr->val ;
            }
            curr = curr->next ;
           
        }
        return head ;
    }
};