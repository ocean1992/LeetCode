int maxProfit(int* prices, int pricesSize) {
    int res = 0 ;
    int mp, lp ;
    mp = lp = prices[0] ;
    for(int i=1 ;i<pricesSize ;i++){
        if(prices[i]>=mp){
            mp = prices[i] ;
        }else{
            res += mp-lp ;
            mp = lp = prices[i] ;
        }
    }
    if(mp > lp)
        res += mp-lp ;
    return res ;
}