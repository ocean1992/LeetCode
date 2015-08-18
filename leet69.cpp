class Solution {
public:
      int mySqrt(int x) {
		if(x==0)
			return 0 ;
        int l = 1 ;
        int h = x/2+1 ;
	//	cout << l << ", " << h << endl ;
        bool f = false ;
        while(l<h){
            //cout << l << ", " << h <<endl ;
			int m = (l+h)/2 ;
			//cout << m << endl ;
            if(x/m==m){
                f = true ;
                return m ;
            }
            else{
                if(x/m>m){
                    l= m +1;
                }else{
                    h = m-1 ;
                }
            }
        }
		//cout << "*** " << l <<endl ;
		if(x/l == l)
			return l ;
        if(!f){
            if(x/l>l){
                while(x/l>l){
                    l++ ;
                }
                return l-1 ;
            }else{
                while(x/l<l){
                    l-- ;
                }
                return l ;
            }
        }
    }
};