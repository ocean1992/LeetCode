int *low, *hig;
int count, res ;
int *dp ;

int maxProfit(int k, int* prices, int pricesSize) {
    int mp, lp ;
    
    low = malloc(sizeof(int)*pricesSize) ;
    hig = malloc(sizeof(int)*pricesSize) ;
    int j = 0 ;
    mp = lp = prices[0] ;
    for(int i=1 ;i<pricesSize ;i++){
        if(prices[i]>=mp){
            mp = prices[i] ;
        }else{
            if(mp>lp){
                low[j] = lp ;
                hig[j] = mp ;
             //   hid[j] = j ;
                j++ ;
            }
            mp = lp = prices[i] ;
        }
    }
    if(mp > lp){
        low[j] = lp ;
        hig[j] = mp ;
        j++ ;
    }
    count = j ;
    //start DP ;
    res = 0 ;
    printf("count = %d\n",count) ;
    if(k>pricesSize){
    	printf("k too large!\n");
    	res = 0 ;
    	for(int i=0 ;i<count ;i++){
    		res += hig[i]-low[i] ;
    	}
    	return res ;
    }
    	
    dp = malloc(sizeof(int)*count) ;
    for(int i=0 ;i<count ;i++){
    	dp[i] = 0 ;
    }
    for(int mk=1 ;mk<=k ;mk++){
    	for(int i=0 ;i<count ;i++){
    		for(int j=i ;j<count-1 ;j++){
    			int temp = hig[j]-low[i] + dp[j+1] ;
    			if(temp > dp[i])
    				dp[i] = temp ;
    		}
    		int temp = hig[count-1]-low[i] ;
    		if(temp > dp[i])
    			dp[i] = temp ;
    	}
    	for(int i=count-2; i>=0 ;i--){
    	    if(dp[i]<dp[i+1])
    	        dp[i] = dp[i+1] ;
    	}
    }
   	for(int i=0 ;i<count ;i++){
   		if(dp[i]>res)
   			res = dp[i] ;
   	}
   	printf("res = %d\n", res) ;
   	return res ;
}