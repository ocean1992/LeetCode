class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index[300] ;
        int str_len = s.length() ;
        int res = 0 ;
        for(int i=0 ;i<300 ;i++)
            index[i] = -1 ;
        for(int i=0 ;i<str_len ;i++){
            for(int j=i ;j<str_len ;j++){
                if(index[s[j]] == -1 || index[s[j]]<i || index[s[j]] == j){
                    index[s[j]] = j ;
                    if(j==str_len-1){
                        if(j-i+1>res){
                            res = j-i+1 ;
                        }
                        return res ;
                    }
                }else{
                    int ti = index[s[j]] ;
                    if(j-i>res)
                        res = j-i ;
                    i = ti ;
                    break ;
                }
            }        
        }
        return res ;
    }
};