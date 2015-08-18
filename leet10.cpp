#include <iostream>
#include <vector>
using namespace std ;

class Solution {
    int **dps ;
    string ss, sp ;
public:


    bool isMatch(string s, string p) {
    	//cout << s << ", " << p << endl ;
    	dps = new int*[s.size()+1] ;
    	for(int i=0 ;i<s.size()+1 ;i++){
    		dps[i] = new int[p.size()+1] ;
    		for(int j=0 ;j<p.size()+1 ;j++){
    			dps[i][j] = -1 ;
    		}
    	}
    	ss = s ;
    	sp = p ;
    	return dp(0, 0) ;
    }

    bool dp(int i, int j){
    	//cout << i << ", " << j << endl ;
    	if(i>=ss.size())
    		i=ss.size() ;
    	if(j>=sp.size()) 
    		j = sp.size() ;
    	if(i<ss.size() && j>=sp.size())
    		return false ;
    	if(i>=ss.size() && j>=sp.size())
    		return true ;
    	if(dps[i][j] != -1)
    		return dps[i][j] ;
        int np, ns ;
        np = j ;
        ns = i ;
    	while(np < sp.size() || ns < ss.size()){
    		//只有两个都移动到末尾才算匹配成功
    		//cout << np << ", " << ns << ", " << sp.size() << ", " << ss.size() << endl ;
    		if(np<sp.size()-1 && sp[np+1] == '*'){
    			if(dp(ns, np+2))
    				dps[i][j] = true ;
    			else{
    				if(ns <ss.size() && np<sp.size()){
    					dps[i][j] = compare(ss[ns],sp[np]) && dp(ns+1,np) ;
    				}else
    					dps[i][j] = false ;
    			}
    			return dps[i][j] ;
    		}else{
    			if(ns<ss.size() && np<sp.size() && compare(ss[ns++], sp[np++])){

    			}else
    				return false ;
    		}
    	}
    	return true ;
    }

    bool compare(char cs, char cp){
    	return cs==cp || cp=='.' ;
    }
};

int main(){
	Solution sl ;
	string ts, tp ;
	while(1){
		cin >> ts >> tp ;
		cout << sl.isMatch(ts, tp) << endl;
	}
}