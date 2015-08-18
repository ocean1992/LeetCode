int maxProfit(int* prices, int pricesSize) {
    int lower = prices[0] ;
    int res = 0 ;
    for(int i=1 ;i<pricesSize ;i++){
        if(prices[i]-lower > res){
            res = prices[i]-lower ;
        }
        if(lower>prices[i])
            lower = prices[i] ;
    }
    return res ;
}