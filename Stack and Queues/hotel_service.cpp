// Problem Description
 
 

// You are travelling to Neverland. After a long journey, 
// you decided to take rest in a hotel for a night.

// You have the map of Neverland in the form of 2D matrix A with dimensions N x M. 

// The rows are numbered from 1 to N, and the columns are numbered from 1 to M.

// You can travel from one cell to any adjacent cell. Two cells are considered 
// adjacent if they share a side.

// In the map, there are only two digits, 0 and 1, 
// where 1 denotes a hotel in that cell, and 0 denotes an empty cell.

// You are also given another 2D array B with dimension Q x 2,
 
// where each row denotes a co-ordinate (X, Y) on the map (1 - indexed). 
// For each coordinate you have to find the distance to the nearest hotel.

// Return an array denoting the answer to each coordinate in the array B.



// **Problem Constraints**
// 1 <= N, M <= 103
// 1 <= Q <= 105
// 0 <= A[i][j] <= 1
// 1 <= B[i][0] <= N
// 1 <= B[i][1] <= M
// There is guranteed to be atleast one hotel on the map.


// **Input Format**
// The first argument is the 2D integer array A.
// The second argument is the 2D integer array B.


// **Output Format**
// Return an integer array denoting the answer to each coordinate in the array B.






// i Have solve this problem using multisource bfs;






vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {
    
    
    int n = A.size();
    int m = A[0].size();
    
    // avoid array cauz avoid tle
    queue<pair<int,int>> q;

    // visited array
    vector<vector<bool>> visited(n,vector<bool>(m,false));

    // storing minm distance
    vector<vector<int>> ans(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]){
                // pushing all 1's position
                q.push({i,j});
                visited[i][j] = true;
            }
        }
    }
    
    
    int level = 0;
    
    while(!q.empty()){
        
        int size = q.size();
        // for level 
        while(size--){
            auto f = q.front();
            q.pop();
            int x = f.first;
            int y = f.second;
            ans[x][y]= level;
            
            int tempx[] = {0,-1,0,1};
            int tempy[] = {-1,0,1,0};
            
            for(int i=0;i<4;i++){
                int newx = tempx[i]+x;
                int newy = tempy[i]+y;
                
                // if pushing is safe 
                if(newx>=0 && newy>=0 && newx<n && newy<m && !visited[newx][newy]){
                    q.push({newx,newy});
                    visited[newx][newy] = true;
                }
            }
            
        }
        
        // increase the level
        level++;
        
    }
    
    vector<int> res;
    
    for(int i=0;i<B.size();i++){
        res.push_back(ans[B[i][0]-1][B[i][1]-1]);
    }
    
    
    return res;
}
