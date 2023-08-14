// Problem Description
 
 

// You are given an integer array A of length N.

// For every integer X in the array, you have to find out the number of integers Y, 
// such that 1 <= Y <= X, and the number of divisors of Y is a power of 2.

// For example, 6 has the following divisors - [1, 2, 3, 6]. This is equal to 4,
//  which is a power of 2.

// On the other hand, 9 has the following divisors [1, 3, 9] which is 3, 
// which is not a power of 2.

// Return an array containing the answer for every X in the given array.



// Problem Constraints
// 1 <= N <= 105
// 1 <= Amax <= 106
// Sum of Amax over all test cases will not exceed 5 * 106


// Input Format
// The first argument is the integer array A.


// Output Format
// Return an array containing the answer for every X in the given array.


// Example Input
// Input 1:
// A = [1, 4]
// Input 2:

// A = [5, 10]


// Example Output
// Output 1:
// [1, 3]
// Output 2:

// [4, 8]






bool isPower2(int x){
    
    while(x!=1){
        
        if(x&1)
          return false;
          
        x/=2;
        
       
    }
    
    if(x!=1 and x&1)
       return false;
    
    return true;
}



vector<int> Solution::powerfulDivisors(vector<int> &A) {
    int mx = 0;
    for(int x:A){
        mx = max(mx,x);
    }
    vector<int> divisors(mx+1,0),prefix(mx+1,0);
    vector<int> ans;

    // calculating divisors of number

    for(int i=1;i<=mx;i++){
        for(int j=i;j<=mx;j+=i){
            divisors[j]++;
        }
    }
    
    for(int i=1;i<=mx;i++){

        // checking divisors are power of 2 or not
        if(isPower2(divisors[i])){
            prefix[i]++;
        }
    }
    
    for(int i=1;i<=mx;i++){
        //prefixing the  ans
        prefix[i] += prefix[i-1];
    }
    
    for(int x:A){
        ans.push_back(prefix[x]);
    }
    
    return ans;
}
