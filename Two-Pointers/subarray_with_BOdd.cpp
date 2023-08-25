int Solution::solve(vector<int> &A, int B) {
    
    // with subarray sum
    
    for(int i=0;i<A.size();i++){
        if(A[i]&1){
           A[i]=1; 
        }
        else{
            A[i]= 0;
        }
    }
    
    
    int sum = 0;
    int ans = 0;
    map<int,int> mp;
   mp[0] = 1;
    for(int i:A){
        sum += i;
       
        if(mp.count(sum-B)){
            ans += mp[sum-B];
        }
        
        mp[sum]++;
        
    }
    
    return ans;
}
