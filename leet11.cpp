class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0 ;
        int st = 0 ;
        int ta = height.size()-1 ;
        while(st<ta){
            if(height[st]<height[ta]){
                int ts = height[st]*(ta-st) ;
                res = res<ts?ts:res ;
                st++ ;
            }else{
                int ts = height[ta]*(ta-st) ;
                res = res<ts?ts:res ;
                ta-- ;
            }
        }
        return res ;
        
    }
};