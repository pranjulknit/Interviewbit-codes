

// Problem Description
 
 

// N light bulbs are connected by a wire.

// Each bulb has a switch associated with it, however due to faulty 
// wiring, a switch also changes the state of all the bulbs to the right 
// of current bulb.

// Given an initial state of all bulbs, find the minimum number 
// of switches you have to press to turn on all the bulbs.

// You can press the same switch multiple times.

// Note : 0 represents the bulb is off and 1 represents the bulb is on.


// Problem Constraints
// 0 <= N <= 5e5
// 0 <= A[i] <= 1


// Input Format
// The first and the only argument contains an integer array A, of size N.


// Output Format
// Return an integer representing the minimum number of switches required.


// Example Input
// A = [0 1 0 1]


// Example Output
// 4


// Example Explanation
// press switch 0 : [1 0 1 0]
// press switch 1 : [1 1 0 1]
// press switch 2 : [1 1 1 0]
// press switch 3 : [1 1 1 1]



















int Solution::bulbs(vector<int> &A) {
    
    
    int cnt =0;
    // logic is if there is bulb is off
    // adding all switches then just increase
    // count by 1
    
    for(int i=0;i<A.size();i++){
        A[i]+= cnt;
        
        if(A[i]%2){
            continue;
        }
        else{
            cnt++;
        }
        
        
    }
    
    return cnt;
}
