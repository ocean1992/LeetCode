class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()) ;
        vector<vector<int>> res ;
        if(nums.size()<3)
            return res ;
        for(int i=0 ;i<nums.size() && nums[i]<=0 ;i++){
            if(i>=1 && nums[i] == nums[i-1])
                continue ;
            int j = i+1 ;
            int k = nums.size()-1 ;
            int ta = 0-nums[i] ;
            while(k>j){
                int t = nums[j]+nums[k] ;
                if(t>ta){
                    k-- ;
                    while(k>j && nums[k] == nums[k+1])
                        k-- ;
                }else{
                    if(t==ta){
                            res.push_back({nums[i],nums[j],nums[k]}) ;
                        j++ ;
                        while(j<k && nums[j] == nums[j-1])
                            j++ ;
                        k-- ;
                        while(k>j && nums[k] == nums[k+1])
                            k-- ;   
                    }else{
                        j++ ;
                        while(j<k && nums[j] == nums[j-1])
                            j++ ;
                    }
                }
            }
        }
        return res ;
    }
};