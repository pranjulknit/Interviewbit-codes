// Problem Description
 
 

// Given a large number represent in the form of an integer array A, 
// where each element is a digit.

// You have to find whether there exists any permutation of the array A 
// such that the number becomes divisible by 60.

// Return 1 if it exists, 0 otherwise.



// Problem Constraints
// 1 <= |A| <= 105
// 0 <= Ai <= 9


// Input Format
// The first argument is an integer array A.


// Output Format
// Return a single integer '1' if there exists a permutation, '0' otherwise.


// Example Input
// Input 1:
// A = [0, 6]
// Input 2:

// A = [2, 3]


// Example Output
// Output 1:
// 1
// Output 2:

// 0






int Solution::divisibleBy60(vector<int> &A) {


// the logic is count of zeroes since 60 = 6*10; = 2*3*5*2;
// so if there is no zero then this can't be divisble by 60
// number should also divisble by 3
// and there should atleast one digit divisble by 2




    if(A.size()==1 and A[0]==0){
        return true;
    }
    int zero = 0;
    int two = 0;
    bool three = false;
    int sum =0;
    
    for(int x:A){
        if(x==0){
            zero++;
            continue;
        }
        
        if(x%2==0){
            two++;
        }
        sum+=x;
    }
    
    // if digit sum is divisble by 3 then number is so
    if(sum%3==0){
        three = true;
    }
    
    if(!three){
        return false;
        
    }
    
    if(!zero){
        return false;
    }
    
    if(two){
        return true;
    }
    
    return false;
    
}
