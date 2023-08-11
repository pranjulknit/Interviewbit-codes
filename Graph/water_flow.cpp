// Problem Description

// Given an N x M matrix A of non-negative integers representing 
// the height of each unit cell in a continent, the "Blue lake" touches 
// the left and top edges of the matrix and the "Red lake" touches the right 
// and bottom edges.

// Water can only flow in four directions (up, down, left, or right) from a 
// cell to another one with height equal or lower.

// Find the number of cells from where water can flow to both the Blue and Red lake.



// Problem Constraints
// 1 <= M, N <= 1000

// 1 <= A[i][j] <= 109



// Input Format
// First and only argument is a 2D matrix A.



// Output Format
// Return an integer denoting the number of cells from 
// where water can flow to both the Blue and Red lake.



// Example Input
// Input 1:

//  A = [
//        [1, 2, 2, 3, 5]
//        [3, 2, 3, 4, 4]
//        [2, 4, 5, 3, 1]
//        [6, 7, 1, 4, 5]
//        [5, 1, 1, 2, 4]
//      ]
// Input 2:

//  A = [
//        [2, 2]
//        [2, 2]
//      ]


// Example Output
// Output 1:

//  7
// Output 2:

//  4


// Example Explanation
// Explanation 1:

//  Blue Lake ~   ~   ~   ~   ~ 
//         ~  1   2   2   3  (5) *
//         ~  3   2   3  (4) (4) *
//         ~  2   4  (5)  3   1  *
//         ~ (6) (7)  1   4   5  *
//         ~ (5)  1   1   2   4  *
//            *   *   *   *   * Red Lake
//  Water can flow to both lakes from the cells denoted in parentheses.

// Explanation 2:

//  Water can flow from all cells











void dfs(int i,int j, vector<vector<int>>&A, vector<vector<bool>> &visited){
    
    int n = A.size();
    int m = A[0].size();
    
    visited[i][j] = true;
    
    int delrow[] = {-1,1,0,0};
    int delcol[] = {0,0,-1,1};
    
    for(int k=0;k<4;k++){
        int nrow = i+delrow[k];
        int ncol = j+delcol[k];
        // corner conditions
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m &&  A[i][j]<= A[nrow][ncol]&& !visited[nrow][ncol]){
            dfs(nrow,ncol,A,visited);
        }
    }
}


int Solution::solve(vector<vector<int> > &A) {
    

    // logic is that we call dfs function for edge points
    int n = A.size();
    int m = A[0].size();



    // visited array for blue and red  lakes
    vector<vector<bool>> blue(n+1,vector<bool>(m+1,false));
    vector<vector<bool>> red(n+1,vector<bool>(m+1,false));
    
    for(int i=0;i<n;i++){
        if(!blue[i][0]){
            dfs(i,0,A,blue);
        }
        
       
    }
    
    for(int j=1;j<m;j++){
        if(!blue[0][j]){
            dfs(0,j,A,blue);
        }
    }
    
    for(int i=0;i<n;i++){
        if(!red[i][m-1]){
            dfs(i,m-1,A,red);
        }
    }
    
    
    for(int j=0;j<m;j++){
        
        if(!red[n-1][j]){
            dfs(n-1,j,A,red);
        }
        
    }
    
    int cnt = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // if water flowing from both blue and red
            if(blue[i][j] && red[i][j]){
                cnt++;
            }
        }
    }
    
    
    return cnt;
}
