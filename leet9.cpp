class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
            return false ;
        int ten = 1 ;
        while(x/ten>=10){
            ten = ten*10 ;
        }
        while(ten>1){
            if(x/ten != x%10){
                return false ;
            }
            x = (x%ten)/10 ;
            ten = ten/100 ;
        }
        return true ;
    }
};