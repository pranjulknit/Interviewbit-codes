class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& A, int B) {
      
    
   
    sort(A.begin(),A.end());
    
    int n = A.size();
    
     vector<vector<int>> ans;
    
    for(int i=0;i<n;i++){
      
        if(i!=0 && A[i]==A[i-1]){
            continue;
        }


        for(int j=i+1;j<n;j++){
        
        if(j> i+1 && A[j]==A[j-1]){
            continue;
        }
           

long long int target = (long long int)B-(long long int)A[i]-(long long int)A[j];
            
            int k = j+1;
            int l = n-1;
            
            
            while(k<l){
                
                int sum = A[k]+A[l];
                
                if(sum==target){
                    
                    ans.push_back({A[i],A[j],A[k],A[l]});
                    
                    k++;
                    //l--;
                    

                    while(k<l && A[k]==A[k-1]) k++;

                    // while(k<l && A[l]==A[l+1]) l--;
                }
                else if(sum<target){
                    k++;
                }
                else{
                    l--;
                }
            }
           
        }
         
    }
    
    // vector<vector<int>> res(ans.begin(),ans.end());
    return  ans;


    }
};