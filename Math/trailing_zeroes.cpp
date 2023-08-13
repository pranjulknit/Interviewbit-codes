// Given an integer A, return the number of trailing zeroes in A!.

// Note: Your solution should be in logarithmic time complexity.



// Problem Constraints
// 0 <= A <= 10000000



// Input Format
// First and only argumment is integer A.



// Output Format
// Return an integer, the answer to the problem.







int Solution::trailingZeroes(int A) {
    
    // trailing zeroes are only formed by prime
    // factors of 2 and 5 only 
    // but since in a factorial there will be more numbers of divisble 
    // by2 but not by 5
    // so if we check the only divisble of 5
    // and there is catch also
    // what about if number is greater than 25,125 then there is also one 
    // addition
    
    int ans = 0;
    
    for(int i=5;A/i>=1;i*=5){
        ans += (A/i);
    }
    
    
    return ans;
}
