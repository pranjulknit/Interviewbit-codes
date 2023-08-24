// Problem Description
 
 

// Given two integers representing the numerator and denominator of a 
// fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.


// Problem Constraints
// INTMIN <= A, B <= INTMAX


// Input Format
// The first integer A represents the numerator.
// The second integer B represents the denominator.


// Output Format
// Return a string


// Example Input
// Input 1:
// A = 1
// B = 2
// Input 2:
// A = 2
// B = 1
// Input 3:
// A = 2
// B = 3


// Example Output
// Output 1:
// "0.5"
// Output 2:
// "2"
// Output 3:
// "0.(6)"






string Solution::fractionToDecimal(int A, int B) {
    string ans="";
    
    if(A==0 ) return "0";
    
    if((A<0 && B>0) || (A>0 && B<0)){
         ans+= "-";
    }
   
    // to avoid overflow when there is 
    // negative INT_MIN
  long long int num  = A>0 ? A: -1ll*A;
   long long int  denom =B>0 ? B: -1ll*B;
   // cout<< num <<" "<<denom<<endl;
    ans += to_string(num/denom);
    
    if(num%denom==0){
        return ans;
    }
    
    ans +=".";
    long long int rem = num%denom;
    map<long long int,long long int> mp;
    while(rem != 0){
        
        // remainder is repeating certainly 
        // it is recurring decimal
        if(mp.count(rem)){
            return ans = ans.substr(0,mp[rem])+"("+ans.substr(mp[rem])+")";
        }
        
        // position of rem
        mp[rem] = ans.size();
        
        // multiply rem by 10 and divide it to get 
        // that decimal point 
        // and make sure to update the remainder
         rem *= 10;
         
         ans += to_string(rem/denom);
         
         rem = (rem%denom);
         
        
    }
    
    return ans;
}
