


//Binary Search as classical painter's problem


// There is given an integer array A of size N denoting the heights of N trees.

// Lumberjack Ojas needs to chop down B metres of wood



// Example Input
// Input 1:

//  A = [20, 15, 10, 17]
//  B = 7
// Input 2:

//  A = [4, 42, 40, 26, 46]
//  B = 20


// Example Output
// Output 1:

//  15
// Output 2:

//  36


// Example Explanation*
// Explanation 1:

//  If you the height parameter to 15 then you can chop:
//   5 metres from first tree
//   0 metres from second tree
//   0 metres from third tree
//   2 metres from fourth tree
//   So in total you chopped 7 metres of wood.
// Explanation 2:

//  If you the height parameter to 36 then you can chop:
//   0 metres from first tree
//   6 metres from second tree
//   4 metres from third tree
//   0 metres from fourth tree
//   10 metres from fifth tree
//   So in total you chopped 20 metres of wood.











//comparator for descending - order

bool comp(int x,int y){
    return x>y;
}


//  flag function make sure as sum can cross int limit so make
// long long int
long  int  flag(long int mid,vector<int>&A){
    long long int ans =0;
    
    
    for(int i=0;i<A.size();i++){
        if(A[i]-mid>0){
             ans += A[i]-mid;
        }
        else{
            break;
        }
        
       
    }
    
    return ans;
}

int Solution::solve(vector<int> &A, int B) {
    
    if(A.size()==0) return 0;
   
    int low= 0;
    
    int mx = 0;
    
    for(int x:A){
        mx = max(mx,x);
    }
    sort(A.begin(),A.end(),comp);

    // this will be the max cut can be done
    int high = mx;
    
    int ans = 0;
    while(low<=high){
       long int  mid = low + (high-low)/2;
       long long int check = flag(mid,A);
        
        if(check>=B){
            ans = mid;
            low = mid+1;
        }
        else{
           high = mid-1;
        }
        
    }
    
    return ans;
}
