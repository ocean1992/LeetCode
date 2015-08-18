#include <iostream>
using namespace std ;
//Roman to Integer

class Solution {
	int romans[26] ;
public:
	Solution(){
		init() ;
	}
    int romanToInt(string s) {
        if (s.length() == 0)
        {
        	return 0 ;
        }
        char a, b;
        a = s[0] ;
        int va, vb ;
        va = romans[s[0]-'A'] ;
        for(int i=1 ;i<s.length() ;i++){
        	//cout << "Now : " << s[i] << ", " << va << endl ;
        	if(s[i] == a){
        		va += value(s[i]);
        	}else{
        			if(value(s[i])>value(a)){
        				va = va-2*value(a)+value(s[i]) ;
        			}else{
        				va = va+value(s[i]);
        			}
        	}
        	a = s[i] ;
        }

       // cout << va << endl ;
        return va ;
    }

private:
	void init(){
		for(int i=0 ;i<26 ;i++){
			romans[i] = 0 ;
		}
		romans['I'-'A'] = 1 ;
		romans['V'-'A'] = 5 ;
		romans['X'-'A'] = 10 ;
		romans['C'-'A'] = 100 ;
		romans['L'-'A'] = 50 ;
		romans['D'-'A'] = 500 ;
		romans['M'-'A'] = 1000 ;
	}
	int value(char c){
		return romans[c-'A'] ;
	}
};

int main(){
	string s = "XIII" ;
	Solution sl ;
	while(1){
		cin >> s ;
		cout << sl.romanToInt(s) << endl ;
	}
	//cout << sl.romanToInt(s) << endl ;
}