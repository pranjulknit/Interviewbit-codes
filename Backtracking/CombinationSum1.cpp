#include <bits/stdc++.h>
using namespace std;
// Given an array of candidate numbers A and a target number B, find all unique combinations in A where the candidate numbers sums to B.

// The same repeated number may be chosen from A unlimited number of times.

// Note:

// 1) All numbers (including target) will be positive integers.

// 2) Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).

// 3) The combinations themselves must be sorted in ascending order.

// 4) CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR ... (a1 = b1 AND a2 = b2 AND ... ai = bi AND ai+1 > bi+1)

// 5) The solution set must not contain duplicate combinations.




vector<vector<int>> ans;

void solve(int idx,vector<int> &A,int target,vector<int>&temp){
    

    // base case
    if(idx==A.size()){
        if(target==0){
            sort(ans.begin(),ans.end());
            ans.push_back(temp);
        }
        
        return;
    }

    // if elements is less than target then add in combinations 
    // simaltenously decrease the target

    if(A[idx]<=target){
     temp.push_back(A[idx]);
    solve(idx,A,target-A[idx],temp);

    //backtrack the combinations
    temp.pop_back(); 
    }
    
    solve(idx+1,A,target,temp);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    //array to store temporary combinations
    vector<int> temp;
    //clearing array to avoid memory leaks
    ans.clear();
    
    
    sort(A.begin(),A.end());
    vector<int> arr;
    arr.push_back(A[0]);
    

    // for no duplicates
    for(int i=1;i<A.size();i++){
        if(A[i] != A[i-1]){
            arr.push_back(A[i]);
        }
    }
    
    solve(0,arr,B,temp);

    //sorted combinations
   sort(ans.begin(),ans.end());
    return ans;
}
