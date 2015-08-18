class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tnum ;
        for(int i=0 ;i<nums.size() ;i++)
            tnum.push_back(nums[i]) ;
        sort(tnum.begin(), tnum.end()) ;
        int right = tnum.size()-1 ;
        for(int i=0 ;i<tnum.size() ;i++){
            int x = target-tnum[i] ;
            while(right>0 && tnum[right]>x){
                right-- ;
            }
            if(right != -1){
                if(tnum[right] == x){
                    int id1, id2 ;
                    id1 = id2 = 0 ;
                    while(nums[id1]!=tnum[i])
                        id1++ ;
                    while(nums[id2] != x){
                        id2++ ;
                    }
                    if(id2==id1){
                        id2++ ;
                        while(nums[id2] != x){
                            id2++ ;
                        }
                    }
                    vector<int> res ;
                    res.push_back(id1+1) ;
                    res.push_back(id2+1) ;
                    sort(res.begin(), res.end()) ;
                    return res;
                }
            }
        }
    }
    
    
};