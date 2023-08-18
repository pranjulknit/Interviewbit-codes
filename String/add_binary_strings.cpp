// Problem Description
 
 

// Given two binary strings A and B. Return their sum (also a binary string).


// Problem Constraints
// 1 <= length of A <= 105

// 1 <= length of B <= 105

// A and B are binary strings



// Input Format
// The two argument A and B are binary strings.



// Output Format
// Return a binary string denoting the sum of A and B



// Example Input
// Input 1:
// A = "100"
// B = "11"
// Input 2:
// A = "110"
// B = "10"


// Example Output
// Output 1:
// "111"
// Output 2:
// "1000"


// Example Explanation
// For Input 1:
// The sum of 100 and 11 is 111.
// For Input 2:
 
// The sum of 110 and 10 is 1000.








string Solution::addBinary(string A, string B) {
    
    
    // add string from end

    int n = A.size();
    int m = B.size();
    
    
    int i=n-1;
    int j = m-1;
    
    // to take the carry
    int carry  = 0;
    string ans = "";
    while(i>=0 && j>=0){
        int sum = (A[i]-'0') + (B[j]-'0') + carry;
        
        carry = sum/2;
        
        ans+=to_string(sum%2);
        
        i--,j--;
        
    }
    
    // if string A>B
    while(i>=0){
        
        int sum = (A[i]-'0')+carry;
        carry = sum/2;
        
        ans+=to_string(sum%2);
        i--;
    }
    
     while(j>=0){
        
        int sum = (B[j]-'0')+carry;
        carry = sum/2;
        
        ans+=to_string(sum%2);
        j--;
    }

    // if there is still a carry
    
    if(carry)
    ans+=to_string(carry);
    reverse(ans.begin(),ans.end());
    return ans;
}
