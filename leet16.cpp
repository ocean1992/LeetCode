#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()) ;
        if(nums.size()<3)
            return 0 ;
        int res = nums[0]+nums[1]+nums[2] - target ;
        for(int i=0 ;i<nums.size();i++){
            if(i>=1 && nums[i] == nums[i-1])
                continue ;
            int j = i+1 ;
            int k = nums.size()-1 ;
            int ta = target-nums[i] ;
            while(k>j){
                int t = nums[j]+nums[k] ;
                if(t>ta){
                    if(t-ta<abs(res))
                        res = t-ta ;
                    k-- ;
                    while(k>j && nums[k] == nums[k+1])
                        k-- ;
                }else{
                    if(t==ta){
                        return target ;
                        j++ ;
                        while(j<k && nums[j] == nums[j-1])
                            j++ ;
                        k-- ;
                        while(k>j && nums[k] == nums[k+1])
                            k-- ;   
                    }else{
                        if(ta-t<abs(res))
                            res = t-ta ;
                        j++ ;
                        while(j<k && nums[j] == nums[j-1])
                            j++ ;
                    }
                }
            }
        }
        return res+target ;
    }
};

int main(){
	Solution sl ;
	int a[] = {6,-18,-20,-7,-15,9,18,10,1,-20,-17,-19,-3,-5,-19,10,6,-11,1,-17,-15,6,17,-18,-3,16,19,-20,-3,-17,-15,-3,12,1,-9,4,1,12,-2,14,4,-4,19,-20,6,0,-19,18,14,1,-15,-5,14,12,-4,0,-10,6,6,-6,20,-8,-6,5,0,3,10,7,-2,17,20,12,19,-13,-1,10,-1,14,0,7,-3,10,14,14,11,0,-4,-15,-8,3,2,-5,9,10,16,-4,-3,-9,-8,-14,10,6,2,-12,-7,-16,-6,10} ;
	vector<int> ab(a,a+108);
	cout << sl.threeSumClosest(ab, -52) << endl;
	return 0 ;

}