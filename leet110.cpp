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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true ;
        return dfs(root) ;
        
    }
    bool dfs(TreeNode* x){
        x->val = 0 ;
        int lh, rh ;
        if(x->left == NULL){
            lh = 0;
        }else {
            if (!dfs(x->left)){
                return false ;
            }
            lh = x->left->val ;
        }
        if(x->right == NULL){
            rh = 0 ;
        }else {
            if (!dfs(x->right)){
                return false ;
            }
           rh = x->right->val ;
        }
        if(lh-rh<-1 || lh-rh>1){
            return false ;
        }
        if(lh>rh)
            x->val = lh+1 ;
        else
            x->val = rh+1 ;
        return true ;
    }
};