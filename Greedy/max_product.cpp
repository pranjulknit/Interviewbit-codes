int Solution::maxp3(vector<int> &A) {
    
    // by sort;
    
    sort(A.begin(),A.end());
    
    
    // logic if all neg or pos or only one positive 
    // then ans will be product of last three numbers;
    // if only before last two were negative
    // then we have to first,second ,last number;
    int n = A.size();
    return max(A[n-1]*A[n-2]*A[n-3],A[0]*A[1]*A[n-1]);
}
