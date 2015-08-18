class Solution {
public:
    int countDigitOne(int n) {
    	long long nn = n ;
        long long sum = 0 ;
        long long t = 1 ;
        while(nn/t>0){
            sum += (nn/(t*10))*t ;
            int x = n%(t*10) ;
            if(x>=2*t)
                sum += t ;
            else{
                if(x>=t)
                    sum += x-t+1 ;
            }
            t=t*10 ;
        }
        return sum ;
    }
};