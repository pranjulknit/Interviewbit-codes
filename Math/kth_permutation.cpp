// Problem Description

// You are given an integer A which represents the length of a permutation.
//  A permutation is an array of length A where all the elements occur exactly once and in any order.
//  For example, [3, 4, 1, 2], [1, 2, 3] are examples of valid permutations while [1, 2, 2], [2] are not.

// You are also given an integer B.
//  If all the permutation of length A are sorted lexicographically, return the Bth permutation.



// Problem Constraints

// 1 <= A <= 105
// 1 <= B <= min(1018, A!), where A! denotes the factorial of A.


// Input Format

// The first argument is the integer A.
// The second argument is the long integer B.














vector<int> Solution::findPerm(int A, long B) {
    
    vector<long long int> fact(21,1);
    
    // since B! couldn't be greater than 20!

    //precomputing the factorial
    for(int i=1;i<=20;i++){
        fact[i] = fact[i-1]*i;
        
    }
    
    set<int> st;
    
    for(int i=1;i<=A;i++){
        st.insert(i);
    }
    
    vector<int> ans(A);
    int i = 0;
    int n = A;
    int cnt = 1;
    while(st.size()!=0){
         auto it = st.begin();
        if(n-cnt>20){
             // if n> 20!
             ans[i] = *it;
           
        }
        else{

            // just divide by n-1! get that index on 
        int index = B/fact[A-1];
         
        
            if(B%fact[A-1]==0){
                 index--;
            }
        
       
        
        
        for(int j=0;j<index;j++){
            it++;
        }
        
        // also decrease the position
        B -= index*fact[A-1];
          ans[i] = *it;
     
        }
        
        cnt++;
        
        A--;
         st.erase(*it);
        i++;
        
    }
    
    
    return ans;
}
