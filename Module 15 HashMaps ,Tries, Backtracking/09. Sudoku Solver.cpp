/*
  TIME COMPLEXITY = O(9^M) WHERE M IS NUMBER OF BLANK SPACES
  SPACE COMPLEXITY = O(1) NO AUXILLARY SPACE IS USED
*/

#include <bits/stdc++.h> 
bool isSAFE(vector<vector<int>>&grid, int row, int col, int val){
        
        for(int i=0; i<9; i++){
            
            if(grid[row][i] == val)
                return false;
                
            if(grid[i][col] == val)
                return false;
                
            if( grid[ 3*(row/3)+(i/3) ] [ 3*(col/3)+(i%3) ] == val )
                return false;
                
        }
        return true;
    }
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(vector<vector<int>>&grid)  
    { 
        
        for(int row=0; row<9; row++){
            
            for(int col=0; col<9; col++){
                
                if(grid[row][col] == 0){
        
                    for(int val=1; val<=9; val++){
                        
                        if(isSAFE(grid, row, col,val)){

                            grid[row][col] = val;

                            bool nextCall = SolveSudoku(grid);
                        
                            if(nextCall){
                                return true;
                            }
                            else{
                                // BACK TRACKING
                                grid[row][col] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }




void solveSudoku(vector<vector<int>>& grid)
{
     bool completed = SolveSudoku(grid);  
}
