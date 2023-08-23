// Problem Description
 
 

// You are given an array of N non-negative integers, A0, A1,..., AN-1.
// Considering each array element Ai as the edge length of some line segment, 
// count the number of triangles that you can form using these array values.

// Notes:
// You can use any value only once while forming each triangle. The order of 
// choosing the edge lengths doesn't matter. Any triangle formed should have a 
// positive area.
// Return answer modulo 109 + 7.


// Problem Constraints
// 1 <= |A| <= 105
// 0 <= Ai <= 106


// Input Format
// The first argument is an integer array A.


// Output Format
// Return an integer equal to the count of the number of triangles that you can form.


// Example Input
// A = [1, 1, 1, 2, 2]


// Example Output
// 4





int Solution::nTriang(vector<int> &A) {

    // for sides to have to be triangle two sides sum > another one


    
    int n = A.size();
    long long int ans = 0;
    int mod = 1e9+7;

    // sorting will be done for optimization
    sort(A.begin(),A.end());

    for(int i=n-1;i>=2;i--){

        // select side from end and check rest side starting from left 
        // can form trianlge or not
        int left = 0;
        int right = i-1;
        
        while(left<right){
            
            int sum = A[left]+A[right];
            
            if(sum>A[i]){
                
                ans += (right-left)%mod;
                ans %=mod;
                right--;
            }
            else{
                left++;
            }
        }
    }
    
    return ans;
}
