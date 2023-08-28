// Problem Description
 
 

// An integer interval [X, Y] (for integers X < Y) is a set of all consecutive
//  integers from X to Y, including X and Y.

// You are given a 2D array A with dimensions N x 2, where each row denotes an 
// interval.

// Find the minimum size of a set S such that for every integer interval Z in A, 
// the intersection of S with Z has a size of at least two.



// Problem Constraints
// 1 <= N <= 105
// 1 <= A[i][0] < A[i][1] <= 109


// Input Format
// The first argument is a 2D integer array A.


// Output Format
// Return a single integer denoting the minimum size of S.


// Example Input
// Input 1:
// A = [[1, 3], [1, 4], [2, 5], [3, 5]]
// Input 2:

// A = [[1, 2], [2, 3], [2, 4], [4, 5]]


// Example Output
// Output 1:
// 3
// Output 2:

// 5


// Example Explanation
// Explanation 1:
// Consider the set S = {2, 3, 4}.  For each interval, there are at least 2 elements
//  from S in the interval.
// Also, there isn't a smaller size set that fulfills the above condition.
// Thus, we output the size of this set, which is 3.
// Explanation 2:

// An example of a minimum sized set is {1, 2, 3, 4, 5}.





int Solution::setIntersection(vector<vector<int> > &A) {
    
    // sorting by end if end are not equal 
    // which has less end that come first
    
    
    sort(A.begin(),A.end(),[](vector<int> &a,vector<int> &b){
        if(a[1]!=b[1]){
           return  a[1]<b[1];
        }
        
        
        return a[0] >  b[0];
    });
    
    
    int x = -1;
    int y = -1;
    int ans = 0;
    for(auto v:A){
        int low = v[0];
        int high = v[1];
        
        
        if(y<low){
            // if existing high is less than 
            // coming low then it increse the ans by 2
            ans += 2;
            
            x = high-1;
            y = high;
        }
        else if(x<low){
            // means y>=low
            // one number already exists in that range
            
            ans +=1;
            x = y;
            y = high;
        }
        
    }
    
    return ans;
}


