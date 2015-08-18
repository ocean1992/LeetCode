int titleToNumber(char* s) {
    if(s[0] == '\0')
        return 0 ;
    int res = 0;
    int i=0 ;
    for (i=0 ;s[i] != '\0';i++){
        res = res*26+s[i]-'A'+1 ;
    }
    return res ;
}