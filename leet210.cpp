class Solution {
	bool *visited ;
	bool *finished ;
	vector<int> res ;
	vector<vector<int> > linjie ;
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
       	for(int i=0 ;i<numCourses ;i++){
       		vector<int> t ;
       		linjie.push_back(t) ;
       	}
       	vector<int> start ;

       	for(int i=0 ;i<prerequisites.size() ;i++){
        	linjie[prerequisites[i].second].push_back(prerequisites[i].first) ;
       	}

       	//完成邻接矩阵的构建
       	visited = new bool[numCourses] ;
       	finished = new bool[numCourses] ;
       	bool *f = new bool[numCourses] ;
       	for(int i=0 ;i<numCourses ;i++){
       		visited[i] = false ;
       		finished[i] = false ;
       		f[i] = true ;
       	}
       	for(int i=0 ;i<prerequisites.size() ;i++){
       		f[prerequisites[i].first] = false ;
       	}
       	for(int i=0 ;i<numCourses ;i++){
       		if (f[i])
       		{
       			start.push_back(i) ;
       		}
       	}
       	for(int i=0 ;i<start.size() ;i++){
       		bool res = dfs(start[i]) ;
       		if (!res)
       		{
       			vector<int> temp ;
       			return temp ;
       		}
       	}
       	vector<int> tres ;
       	if(res.size() != numCourses){
       		return tres ;
       	}
       	for(int i=res.size()-1 ;i>=0 ;i--){
       		tres.push_back(res[i]) ;
       	}
       	return tres ;
    }

    bool dfs(int x){
    	if(!visited[x]){
    		visited[x] = true ;
    		for(int j=0 ;j<linjie[x].size() ;j++){
    			if(!dfs(linjie[x][j])){
    				return false ;
    			} 
    		}
    		finished[x] = true ;
    		res.push_back(x) ;
    	}else{
    		if(!finished[x]){
    			//环边
    			return false ;
    		}
    	}
    	return true ;
    }
};