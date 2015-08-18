#include <iostream>
#include <string.h>
#include <vector> 
using namespace std ;
//Integer to Roman

class Solution {
	char romans[3][11] ;
public:
    string intToRoman(int num) {
    	char res[100] ;
        int val[4] ;
        val[0] = val[1] = val[2] = val[3] = 0 ;
        int cnum = num ;
        int co = 0 ;
        int id = 0 ;
        while(cnum>0){
        	val[co++] = cnum%10 ;
        	cnum = cnum/10 ;
        }
        for(int i=0 ;i<val[3] ;i++){
        	res[id++] = 'M' ;
        }
        for(int i=2 ;i>=0 ;i--){
        	int t = val[i] ;
        	if(romans[i][t] != 'a'){
        		res[id++] = romans[i][t] ;
        	}else{
        		if(t<=3){
        			for(int j=0 ;j<t ;j++)
        				res[id++] = romans[i][1] ;
        		}else{
        			if(t<=8){
	        			for(int j=0 ;j<5-t ;j++){
	        				res[id++] = romans[i][1] ;
	        			}
	        			res[id++] = romans[i][5] ;
	        			for(int j=0 ;j<t-5 ;j++){
	        				res[id++] = romans[i][1] ;
	        			}
	        		}else{
	        			for(int j=0 ;j<10-t ;j++){
	        				res[id++] = romans[i][1] ;
	        			}
	        			res[id++] = romans[i][10] ;
	        		}
        		}
        	}
        }
        res[id++] = '\0' ;
        string s(res) ;
        return s ;
    }

    Solution(){
    	for(int i=0 ;i<3 ;i++){
    		for(int j=0 ;j<11 ;j++)
    			romans[i][j] = 'a' ;
    	}
    	romans[0][1] = 'I' ;
    	romans[0][5] = 'V' ;
    	romans[0][10] = 'X' ;
    	romans[1][1] = 'X' ;
    	romans[1][5] = 'L' ;
    	romans[1][10] = 'C' ;
    	romans[2][1] = 'C' ;
    	romans[2][5] = 'D' ;
    	romans[2][10] = 'M' ;
    }
};

int main(){
	Solution sl ;
	while(1){
		int x ;
		cin >> x ;
		cout << sl.intToRoman(x) << endl ;
	}
}



