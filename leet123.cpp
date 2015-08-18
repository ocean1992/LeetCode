int maxProfit(int* prices, int pricesSize) {
    int mp, lp ;
    int *low, *hig, *mhig ;
    low = malloc(sizeof(int)*pricesSize) ;
    hig = malloc(sizeof(int)*pricesSize) ;
    mhig = malloc(sizeof(int)*pricesSize) ;
    //hid = malloc(sizeof(int)*pricesSize) ;
    int j = 0 ;
    mp = lp = prices[0] ;
    for(int i=1 ;i<pricesSize ;i++){
        if(prices[i]>=mp){
            mp = prices[i] ;
        }else{
            if(mp>lp){
                low[j] = lp ;
                mhig[j] = hig[j] = mp ;
             //   hid[j] = j ;
                j++ ;
            }
            mp = lp = prices[i] ;
        }
    }
    if(mp > lp){
        low[j] = lp ;
        mhig[j] = hig[j] = mp ;
       // hid[j] = j;
        j++ ;
    }
    printf("j = %d\n", j) ;
    for(int i=j-2 ;i>=0 ;i--){
        if(mhig[i+1]>hig[i]){
            mhig[i] = mhig[i+1] ;
        }
    }
    mhig[j-1] = mhig[j-1]-low[j-1] ;
    for(int i=j-2 ;i>=0 ;i--){
    	mhig[i] = mhig[i]-low[i] ;
    	if(mhig[i]<mhig[i+1])
    		mhig[i] = mhig[i+1] ;
    }
    int res = 0 ;
    for(int i=0 ;i<j ;i++){
    	printf("%d, %d, %d\n",low[i],hig[i], mhig[i]) ;
        if(mhig[i]>res){
            res = mhig[i] ;
        }
    }
    printf("single res = %d\n", res) ;
    for(int i=0 ;i<j-1 ;i++){
        for(int k=i ;k<j-1 ;k++){	
            int temp = hig[k]-low[i] + mhig[k+1] ;
            if(temp>res)
                res = temp ;
        }
    }
    return res ;
}