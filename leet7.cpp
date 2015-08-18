class Solution {
public:
    int reverse(int x) {
        int mx = x ;
        if(mx<0){
            mx = -x ;
        }
		int hold[] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7} ;
		int maxbit = 10 ;
        int id = 0 ;
        int bt[20] ;
        while(mx>0){
            bt[id++] = mx%10 ;
            mx = mx/10 ;
        }
		if(id>=10){
			bool overflow = false ;
			for(int i=0 ;i<id ;i++){
				if(bt[i] > hold[i]){
					overflow = true ;
					break ;
				}else{
					if(bt[i] < hold[i]){
						break ;
					}
				}
			}
			if(overflow)
				return 0 ;
		}
		int res = 0 ;
		int ten = 1; 
        for(int i=id-1 ;i>=0 ;i--){
            res += bt[i]*ten ;
			ten = ten*10 ;
        }
		if(x<0)
			return 0-res ;
		else
			return res ;
        
    }
};