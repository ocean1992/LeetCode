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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false ;
        ListNode *x, *y ;
        x = y = head ;
        do{
            //x move one step ;
            x = x->next ;
            //y move two steps ;
            if(x == NULL)
                return false ;
            y = y->next ;
            if(y == NULL)
                return false ;
            y = y->next ;
            if(y == NULL)
                return false ;
        }while(x != y) ;
        return true ;
    }
};