class Solution {
public:
    string convert(string s, int numRows) {
        int mm = 2*numRows-2 ;
        if(mm==0){
            return s ;
        }
            int t = s.length()/mm +1 ;
            char* str = new char[s.length()+1] ;
            //line 0 
            int id ;
            for(int i=0 ;i<t ;i++){
                if(i*mm<s.length())
                    str[id++] = s[i*mm] ; 
            }
            for(int ll=1 ;ll<numRows-1 ;ll++){
                for(int i=0 ;i<t ;i++){
                    if(i*mm+ll < s.length())
                        str[id++] = s[i*mm+ll] ;
                    if(i*mm+mm-ll <s.length())
                        str[id++] = s[i*mm+mm-ll] ;
                }
            }
            for(int i=0 ;i<t ;i++){
                if(i*mm+numRows-1 < s.length())
                    str[id++] = s[i*mm+numRows-1] ;
            }
            str[id] = '\0' ;
            string res(str); 
            return res ;
    }
};