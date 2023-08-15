// Problem Description
 
 

// Given a positive integer that fits in a 32-bit signed integer, 
// find if it can be expressed as A^P where P > 1 and A > 0.
// A and P both should be integers.


// Problem Constraints
// 1 <= A <= 109


// Input Format
// The first argument is an integer A.


// Output Format
// Return an integer, 1 for True, 0 for False


// Example Input
// A = 4


// Example Output
// 1


// Example Explanation
// A = 4, it can be written as 2 ^ 2







int Solution::isPower(int A) {
    
    // logic is find the factors  and if they 
    // occurs in any pair of coprime aur only one
    // then their couldn't be power of more than 1
    
   
    set<int> div;
    for(int i=2;i*i<=A;i++){
        int cnt= 0;
        while(A!=1 && A%i==0){
            A /= i;
            cnt++;
        }
        
        if(cnt){
            div.insert(cnt);
        }
        
    }
   // cout<<prime.size()<<endl;
   
    
    if(A!=1){
        return 0;
    }
    auto it = div.begin();
    int gcd = *it;

    
    // gcd is for calculating that it is not 1
    for(auto it:div){
        int x = it;
        gcd = __gcd(gcd,x);
    }
   
    return gcd!=1;
    
}
