#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end()) ;
        vector<vector<int> > res ;
        int offset = nums[0] ;
        if(offset>0)
        	offset = 0 ;
        for(int i=0 ;i<nums.size() && nums[i]<target-3*offset;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue ;
            for(int j=i+1 ;j<nums.size() && target-nums[i]-2*offset ;j++){
                if(j>i+1 && nums[j]==nums[j-1])
                    continue ;
                int k = j+1 ;
                int m = nums.size()-1 ;
                int ta = target-nums[i]-nums[j] ;
                while(k<m){
                    int tt = nums[k]+nums[m] ;
                    if(tt<ta){
                        k++ ;
                        while(nums[k] == nums[k-1] && k<m )
                            k++ ;
                    }else{
                        if(tt>ta){
                            m-- ;
                            while(nums[m+1] == nums[m] &&m>k)
                                m-- ;
                        }else{
                        	int taa[] = {nums[i],nums[j],nums[k], nums[m]} ;
                            vector<int> abc(taa, taa+4) ;
                            res.push_back(abc) ;
                            k++ ;
                            while(nums[k] == nums[k-1] && k<m )
                                k++ ;
                            m-- ;
                            while(nums[m+1] == nums[m] &&m>k)
                                m-- ;
                        }
                    }
                }
            }
        }
        for(int i=0 ;i<res.size() ;i++){
        	for(int j=0 ;j<res[i].size() ;j++)
        		cout << res[i][j] << ", " ;
        	cout << endl ;
        }
        return res ;
    }
};

int main(){
	Solution sl ;
	//int a[] = {6,-18,-20,-7,-15,9,18,10,1,-20,-17,-19,-3,-5,-19,10,6,-11,1,-17,-15,6,17,-18,-3,16,19,-20,-3,-17,-15,-3,12,1,-9,4,1,12,-2,14,4,-4,19,-20,6,0,-19,18,14,1,-15,-5,14,12,-4,0,-10,6,6,-6,20,-8,-6,5,0,3,10,7,-2,17,20,12,19,-13,-1,10,-1,14,0,7,-3,10,14,14,11,0,-4,-15,-8,3,2,-5,9,10,16,-4,-3,-9,-8,-14,10,6,2,-12,-7,-16,-6,10} ;
	int a[] = {-1, -5, -5, -3, 2, 5, 0, 4} ;
	vector<int> ab(a,a+8);
	sl.fourSum(ab, -7) ;
	return 0 ;

}