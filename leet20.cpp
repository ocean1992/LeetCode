class Solution {
public:
    bool isValid(string s) {
        char *stack = new char[s.size()] ;
        int pos = 0 ;
        for(int i=0 ;i<s.size() ;i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack[pos++] = s[i] ;
            }else{
                if(pos==0)
                    return false ;
                switch(s[i]){
                    case ')' :
                        if(stack[pos-1] == '(')
                            pos-- ;
                        else
                            return false ;
                        break ;
                    case ']' :
                        if(stack[pos-1] == '[')
                            pos-- ;
                        else
                            return false ;
                        break ;
                    case '}' :
                        if(stack[pos-1] == '{')
                            pos-- ;
                        else
                            return false ;
                        break ;
                }
            }
        }
        if(pos!=0)
            return false ;
        return true ;
    }
};