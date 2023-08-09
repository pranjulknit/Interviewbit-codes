


// Given 2 integers A and B and an array of integers C of size N. 
Element C[i] represents the length of ith board.
//  You have to paint all N boards [C0, C1, C2, C3 … CN-1]. 
There are A painters available and each of them takes B units of time to paint 1 unit of the board.

// Calculate and return the minimum time required to paint all boards 
under the constraints that any painter will only paint contiguous sections of the board.
//  NOTE: 
//  1. 2 painters cannot share a board to paint. That is to say, 
a board cannot be painted partially by one painter, and partially by another.
//  2. A painter will only paint contiguous boards. This means a configuration where painter 1 paints boards 1 and 3 but not 2 is invalid.

//  Return the ans % 10000003.



// Problem Constraints
// 1 <= A <= 1000

// 1 <= B <= 106

// 1 <= N <= 105

// 1 <= C[i] <= 106



// Input Format
// The first argument given is the integer A.

// The second argument given is the integer B.

// The third argument given is the integer array C.





















bool check(int p,vector<int>&C,int mid){
    
    int cnt = 1;
   long long  int sum =0;
    for(int i=0;i<C.size();i++){
        //if number is greater than mid return false;
        if(C[i]>mid){
            return false;
        }
        // checking everytime adding this number can't override mid
     if(sum+C[i]<=mid){
         sum+=C[i];
     }
     else{// if so then we have to increase painters
         sum = C[i];
         cnt++;
     }
     // when total painters are more than given painter
        if(cnt>p){
            return false;
        }
        
    }
    
    return true;
}


int Solution::paint(int A, int B, vector<int> &C) {
    
    
    int n = C.size();
   // sort(C.begin(),C.end());
    int sum = 0;
    long long  int ans = 0;
    for(int x:C){
        sum+=x;
       
    }
   long long  int low = 0;
   long long  int high = sum;
  
    while(low<=high){
        
       long long  int mid = low + (high-low)/2;
        
        if(check(A,C,mid)){
            ans  = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    long long int res = (ans*B)%10000003;
    return res;
}
