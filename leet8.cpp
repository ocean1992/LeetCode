class Solution {
public:
    int myAtoi(string str) {
        int len = str.size() ;
        if(len == 0)
            return 0 ;
        int id = 0 ;
        bool negtive = false ;
        while(str[id] == ' ' || str[id] == '\t')
            id++ ;
        if(str[id] == '-' || str[id] == '+'){
            if(str[id] == '-')
                negtive =true ;
            id++ ;
        }
        else{
            if(str[id]<'0' || str[id]>'9')
                return 0 ;
        }
        while(str[id] == '0')
            id++ ;
        int ten = 1 ;
        int res = 0 ;
        int end = len-1 ;
        while(str[end]==' ')
            end-- ;
        for(int i=end ;i>=id ;i--){
            if(str[i]<'0' || str[i]>'9'){
                ten = 1 ;
                res = 0 ;
                end = i-1 ;
            }
            else{
                res += ten*(str[i]-'0') ;
                ten = ten*10 ;
            }
        }
        //overflow :
        int imax = 2147483647 ;
        int imin = -2147483648 ;
        int overf[10] = {2,1,4,7,4,8,3,6,4,7} ;
        bool over = false ;
        if(end-id+1>10){
            over = true ;
        }else{
            if(end-id+1==10){
                for(int i=id ;i<=end ;i++){
                    if(i==end && negtive){
                        if(str[i]-'0'>8){
                            over = true ;
                            break ;
                        }
                    }else{
                        if(str[i]-'0'>overf[i-id]){
                            over = true;
                            break ;
                        }else{
                            if(str[i]-'0'<overf[i-id])
                                break ;
                        }
                    }
                }
            }
        }
        if(over){
            if(negtive)
                return imin ;
            else
                return imax ;
        }
        if(negtive)
            return -res ;
        return res ;
    }
};