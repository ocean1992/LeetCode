class Solution {
public:
          int boardRowSize ;
    int boardColSize ;
    void solve(vector<vector<char> > &board) {
        boardRowSize = board.size() ;
        if(boardRowSize == 0)
            return ;
        boardColSize = board[0].size() ;
        bool **fl = new bool*[boardRowSize] ;
        for(int i=0 ;i<boardRowSize ;i++)
            fl[i] = new bool[boardColSize] ;
        for(int i=0 ;i<boardRowSize ;i++){
            for(int j=0 ;j<boardColSize ;j++){
                fl[i][j] = false ;
            }
        }
        for(int i=0 ;i<boardRowSize ;i++){
            dfs(board,fl,i,0) ;
            dfs(board,fl,i,boardColSize-1) ;
        }
        for(int j=0 ;j<boardColSize ;j++){
            dfs(board,fl,0,j) ;
            dfs(board,fl,boardRowSize-1,j) ;
        }
        for(int i=0 ;i<boardRowSize ;i++){
            for(int j=0 ;j<boardColSize ;j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X' ;
                else{
                    if(board[i][j] == 'Z')
                        board[i][j] = 'O' ;
                }
            }
        }
    }
    
    void dfs(vector<vector<char> > &board,bool **fl,int ti, int tj){
    	int di[4] = {-1, 1, 0, 0} ;
        int dj[4] = {0, 0, 1, -1} ;
    	stack<int> si ;
    	stack<int> sj ;
    	si.push(ti) ;
    	sj.push(tj) ;
    	int ci, cj ;
    	while(!si.empty()){
    		ci = si.top() ;
    		cj = sj.top() ;
    		si.pop() ;
    		sj.pop() ;
    		if(ci<0 || cj<0 || ci>=boardRowSize || cj>=boardColSize){
            	continue ;
        	}
        	if(board[ci][cj] == 'X' || board[ci][cj] == 'Z' || fl[ci][cj]){
        		continue ;
        	}
        	fl[ci][cj] = true ;
        	board[ci][cj] = 'Z' ;
        	for(int i=0 ;i<4 ;i++){
        		si.push(ci+di[i]) ;
        		sj.push(cj+dj[i]) ;
        	}
    	}

    }
};
