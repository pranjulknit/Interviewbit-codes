





// Given an array of all positive integers and an element “x”. 

// You need to find out whether all array elements can be made 
// equal or not by performing any of the 3 operations: add x to any 
// element in array, subtract x from any element from array, do nothing.

//  This operation can be performed only once on an element of array.



// Input 1:
// A=[2,3,1]
// X=1
// Input 2:

// A=[2,3,1]
// X=2







int Solution::solve(vector<int> &A, int B) {
    
    
    sort(A.begin(),A.end());
    
    
    for(int i=1;i<A.size();i++){
        if(A[i]-A[i-1]==B or A[i]-A[i-1]==0){
            continue;
        }
        else{
            return 0;
        }
    }
    
    return 1;
}
