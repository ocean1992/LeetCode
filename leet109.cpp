/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL ;
        ListNode *x = head ;
        int len = 0 ;
        while(x != NULL){
            len++ ;
            x = x->next ;
        }
        return generateSubTree(head, len);
    }
    
    TreeNode* generateSubTree(ListNode* st, int m){
       
        if(st == NULL || m<=0)
            return NULL ;
        if(m==1){
            TreeNode *t = new TreeNode(st->val) ;
            return t ;
        }
        ListNode* z = getNode(st, m/2) ;
        TreeNode *root = new TreeNode(z->val) ;
        root->left = generateSubTree(st,m/2) ;
        root->right = generateSubTree(z->next, (m-1)/2) ;
        return root ;
    }
    
    ListNode* getNode(ListNode* head, int n){
        int x = 0 ;
        ListNode* y = head ;
        while(y != NULL && x<n){
            y = y->next ;
            x++ ;
        }
        return y ;
    }
};