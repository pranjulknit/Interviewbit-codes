int Solution::solve(string A) {
    
    int i = 0;
    int j = A.size()-1;
    int ans =0 ;
    
    while(i<j){
        if(A[i]==A[j]){
            i++,j--;
            
        }
        else{
            ans++;
            i = ans;
            j = A.size()-1;
        }
    }
    
    return ans;
}
