
// Problem Description
 
 

// Given an even number ( greater than 2 ), return two prime 
// numbers whose sum will be equal to the given number.
// If there is more than one solution possible, return the
//  lexicographically smaller solution i.e.
// If [a, b] is one solution with a <= b,
// and [c,d] is another solution with c <= d, then

// [a, b] < [c, d] 
// If a < c OR ( a == c AND b < d ).
// NOTE: A solution will always exist. read Goldbach's conjecture


// Problem Constraints
// 1 <= A <= 2 * 107


// Input Format
// The first argument is an integer A.


// Output Format
// Return an array of integers.


// Example Input
// 4


// Example Output
// [2, 2]


// Example Explanation
// 2 + 2 equals 4, which is the lexicographically smaller solution













vector<int> Solution::primesum(int A) {
    int temp = A;
    vector<int> pr;
    vector<bool> prime(A+1,true);
    for(int i=2;i*i<=A;i++){
        if(prime[i]){
           
            
            for(int j=i*i;j<=A;j+=i){
                prime[j]=false;
            }
        }
        
    }
    
    // all prime number till A
    for(int i=2;i<=A;i++){
        if(prime[i]){
           pr.push_back(i);
        }
    }
    vector<int> ans;
   
    for(int x:pr){
        auto it = find(pr.begin(),pr.end(),A-x);
        if(it!= pr.end()){
            ans.push_back(x);
            ans.push_back(A-x);
            break;
        }
    }
    
    //sort(ans.begin(),ans.end());
    return ans;
    
}
