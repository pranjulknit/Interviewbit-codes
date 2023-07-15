
// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// Each number in C may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// Example :

// Given candidate set 10,1,2,7,6,1,5 and target 8,

// A solution set is:

// [1, 7]
// [1, 2, 5]
// [2, 6]
// [1, 1, 6]











vector<vector<int>> ans;




void solve(int idx,vector<int> &arr,vector<int>&temp,int target){
    
        if(target ==0 ){
            ans.push_back(temp);
         
           return;
        }
        
       
        for(int i=idx;i<arr.size();i++){
            if(i>idx and  arr[i]==arr[i-1]) continue;
             if(arr[i]>target) break; 
          
            temp.push_back(arr[i]);
            solve(i+1,arr,temp,target-arr[i]);
            temp.pop_back();
        }
        
    
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    ans.clear();
    
    vector<int> temp;
    
    sort(A.begin(),A.end());
    
    
    
    solve(0,A,temp,B);
    sort(ans.begin(),ans.end());
    
    return ans;
    
}
