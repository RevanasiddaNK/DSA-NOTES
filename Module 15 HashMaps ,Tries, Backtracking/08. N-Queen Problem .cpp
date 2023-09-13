class Solution{
public:

    void addMatrixtoAns(vector<vector<int>>&matrix, int n, vector<vector<int>>&ans){
        
        vector<int>temp;
        
        /*
        number in the ith place denotes that the ith-column queen is placed in the row with that number
        */
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(matrix[j][i] == 1)
                    temp.push_back(j+1);
                    
            }
        }
        ans.push_back(temp);
    }
    
    bool isSAFE(vector<vector<int>>&matrix, int row, int col, int n){
        
        int x = row;
        int y = col;
        
        // is it in same row (ROW CHECK)
        while(y >= 0){
            
            if(matrix[x][y] == 1)
                return false;
            y--;
        }
        
        // Diagonal Check below
        y = col;
        while(y >=0 && x >= 0){
            if(matrix[x][y] == 1)
                return false;
            y--;
            x--;
        }
        
        // Diagonal Check UPPER
        x = row;
        y = col;
        while(y >=0 && x < n){
            if(matrix[x][y] == 1)
                return false;
            y--;
            x++;
        }
        
        return true;
        
    }

    void solve(vector<vector<int>>&matrix, int col, int n, vector<vector<int>>&ans){
        
        if(col == n){
            addMatrixtoAns(matrix,n,ans);
            return;
        }
        
        for(int i=0; i<n; i++){
            
            if(isSAFE(matrix,i,col,n)){
                matrix[i][col] = 1;
                solve(matrix, col+1, n, ans);
                matrix[i][col] = 0;
            }
           
        }
        
    }

    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>>ans;
        vector<vector<int>>matrix(n,vector<int>(n,0));
        solve(matrix,0,n,ans);
        
        return ans;
        
    }
};
