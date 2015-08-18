#include <vector>
#include <iostream>
using namespace std ;

class Solution {
    vector<string>letters ;
    char *buf ;
    vector<string> res ;
    string input ;
public:
    Solution(){
        string let[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"} ;
        letters = vector<string>(let, let+8) ;
    }
    void tryy(int i){
        if(i==input.size()){
            res.push_back(string(buf)) ;
            cout << string(buf) << endl ;
            return ;
        }
        for(int j=0; j<letters[input[i]-'2'].size() ;j++){
        	cout << j << endl ;
            buf[i] = letters[input[i]-'2'][j] ;
            tryy(i+1) ;
        }
    }
    vector<string> letterCombinations(string digits) {
         res.clear() ;
         if(digits.size()==0)
            return res ;
        buf = new char[digits.size()] ;
        input = digits ;
       
        tryy(0) ;
        return res ;
    }
};

int main(){
	Solution sl ;
	while(1){
		string x ;
		cin >> x ;
		sl.letterCombinations(x) ;
	}
	sl.letterCombinations("2") ;
}