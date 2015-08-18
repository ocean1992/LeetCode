#include <string>

class Solution {
public:
     string longestPalindrome(string s) {
        int len = s.size() ;
        int res = 1 ;
        int start = 0 ;
        
        //jishu
        for(int mid=0 ;mid<len ;mid++){
            int st, end ;
            for(st=mid-1,end=mid+1 ;st>=0 && end<len ;st--,end++){
                if(s[st] != s[end]){
                    if(end-st-1>res){
						
                        res = end-st+1-2 ;
                        start = st+1 ;
						//cout << "   " << mid << ", "<<st << ", " <<res << ", " << s.substr(start, res) << endl ;
                    }
                    break ;
                }else{
                    if(st==0 || end==len-1){
						if (end-st+1 > res){
							res = end-st+1 ;
							start = st ;
						}
                        break ;
                    }
                }
            }
        }
		//cout <<"answer : " << start << ", " <<res << endl ;
        //oushu
        for(int mid=0 ;mid<len ;mid++){
            int st, end ;
            for(st=mid, end=mid+1 ; st>=0 && end<len;st--, end++){
                if(s[st] != s[end]){
                    if(end-st-1 > res){
                        res = end-st+1-2 ;
                        start = st+1 ;
						//cout << "   " << mid << ", "<<st << ", " <<res << ", " << s.substr(start,res)<< endl ;
                    }
                    break ;
                }else{
                    if(st==0 || end==len-1){
                        if (end-st+1 > res){
							res = end-st+1 ;
							start = st ;
						}
                        break ;
                    }
                }
            }
        }
		//cout <<"answer : " << start << ", " <<res << endl ;
        return s.substr(start,res) ;
    }
};