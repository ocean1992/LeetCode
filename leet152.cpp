int maxProduct(int* nums, int numsSize) {
   	int mi, ma ;
    int i = 0 ;
    mi = ma = nums[0] ;
    int res = ma ;
    for(i=1 ;i<numsSize ;i++){
    	int tma = ma*nums[i] ;
    	int tmi = mi*nums[i] ;
    	if(nums[i]>0){
    		ma = tma>nums[i]?tma:nums[i] ;
    		mi = tmi<nums[i]?tmi:nums[i] ;
    	}else{
    		if(nums[i] == 0){
    			ma = mi = 0 ;
     		}else{
     			mi = tma<nums[i]?tma:nums[i] ;
    			ma = tmi>nums[i]?tmi:nums[i] ;
     		}
    	}
    	if(ma>res){
    		res = ma;
    	}
    }
    return res ;
}