class Solution {
    vector<vector<int>> res ;
    vector<int> temp ;
    bool *fl ;
    int n ;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size() ;
        res.clear() ;
        temp.clear() ;
        fl = new bool[n] ; 
        for(int i=0 ;i<n ;i++)
            fl[i] = false ;
        puts(nums) ;
        return res ;
    }
    
    void puts(vector<int>& nums){
        if (temp.size() == n){
            res.push_back(temp) ;
            return ;
        }
        for(int i=0 ;i<n ;i++){
            if(!fl[i]){
                fl[i] = true ;
                temp.push_back(nums[i]) ;
                puts(nums) ;
                temp.pop_back() ;
                fl[i] = false ;
            }
        }
    }
};