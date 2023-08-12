





// Problem Description

// Given are Three arrays A, B and C.

// Return the sorted list of numbers that are present in atleast 
// 2 out of the 3 arrays.



// Problem Constraints
// 1 <= |A|, |B|, |C| <= 100000

// 1 <= A[i], B[i], C[i] <= 100000

// A, B, C may or may not have pairwise distinct elements.



// Input Format
// First argument is the array A.

// First argument is the array B.

// First argument is the array C.



// Output Format
// Return a sorted array of numbers.



// Example Input
// Input 1:

// A = [1, 1, 2]
// B = [2, 3]
// C = [3]
// Input 2:

// A = [1, 2]
// B = [1, 3]
// C = [2, 3]


// Example Output
// Output 1:

// [2, 3]
// Output 2:

// [1, 2, 3]







vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    // storing all the values for atleast 2 values
    map<int,int> mp;
    
    for(int x:A){
        if(mp[x]<1)
           mp[x]++;
    }
    
    // to avoid duplicate elements
    sort(B.begin(),B.end());
    
    for(int i=0;i<B.size();i++){
        
        if(i>0 && B[i]==B[i-1]){
            continue;
        }
        
       
           mp[B[i]]++;
        
    }
    
    sort(C.begin(),C.end());
    
    for(int i=0;i<C.size();i++){
        if(i>0 && C[i]==C[i-1]){
            continue;
        } 
        
       
            mp[C[i]]++;
        
    }
    vector<int> ans;
    for(auto it:mp){
        // if element is found in atleast 2 arrays
        if(it.second>1){
            ans.push_back(it.first);
        }
    }
    
    return ans;
}
