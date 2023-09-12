class Solution{
    public:
    
   bool isSafe(int x, int y,vector<vector<int>>&m,int n,vector<vector<bool>>&visited) {
    if((x >= 0 && y >= 0 && x < n && y < n) && ( m[x][y] == 1 && visited[x][y] == 0))
        return true;
    else
        return false;
}

void solve(vector<vector<int>>&m, int n, int i, int j,vector<vector<bool>>&visited,vector<string>&ans,string str){

        
        if(i == n-1 && j == n-1){
            ans.push_back(str);
            return;
        }

        visited[i][j] = 1;

// DOWN
        if(isSafe(i+1,j,m,n,visited))     
            solve(m,n,i+1,j,visited,ans,str+'D');
// LEFT
        if(isSafe(i,j-1,m,n,visited))
           solve(m,n,i,j-1,visited,ans,str+'L');

// RIGHT
        if(isSafe(i,j+1,m,n,visited))
           solve(m,n,i,j+1,visited,ans,str+'R');
// UP
        if(isSafe(i-1,j,m,n,visited))
           solve(m,n,i-1,j,visited,ans,str+'U');
        
        visited[i][j] = 0;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string>ans;
        string str = "";
      
        vector<vector<bool>>visited(n, vector<bool>(n,0));

        if(m[0][0] == 0)
            return ans;
        
        solve(m,n,0,0,visited,ans,str);
    
        return ans;
    }
};
