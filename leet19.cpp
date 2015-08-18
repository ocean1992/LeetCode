#include <iostream>
using namespace std ;

struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *th = new ListNode(-1) ;
        th->next = head ;
        ListNode *x = head ;
        int i = 1 ;
        while(x!=NULL && i<n){
            x = x->next ;
            i++ ;
        }
        ListNode *y = th ;
        while(x->next!=NULL){
            x = x->next ;
            y = y->next ;
        }
        if(y == th){
            y->next = y->next->next ;
            return y->next ;
        }else{
            y->next = y->next->next ;
            return head ;
        }
    }
};

int main(){
    int n = 5;
    ListNode *head = new ListNode(5) ;
    for(int i=1 ;i<n ;i++){
        ListNode *t = new ListNode(i) ;
        t->next = head ;
        head = t ;
    }
    ListNode *st = head ;
    while(st != NULL){
        cout << st->val << " " ;
        st = st->next ;
    }
    cout << endl ;
    Solution sl ;
    ListNode *res = sl.removeNthFromEnd(head, 5) ;
    while(res != NULL){
        cout << res->val << " " ;
        res = res->next ;
    }
}