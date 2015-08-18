#include <string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int l = 0 ;
        if(strs.size() == 0)
            return "" ;
        for(l=0 ;l<strs[0].length() ;l++){
            bool f = true ;
            char x = strs[0][l] ;
            for(int i=1 ;i<strs.size() ;i++){
                if(l>=strs[i].size() || strs[i][l]!=x){
                    f = false ;
                    break ;
                }
            }
            if(!f)
                break ;
        }
        if(l==0)
            return "" ;
        else
            return strs[0].substr(0,l) ;
    }
};