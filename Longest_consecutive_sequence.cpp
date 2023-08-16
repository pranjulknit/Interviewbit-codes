// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// Example: 

// Given [100, 4, 200, 1, 3, 2],

// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

// Your algorithm should run in O(n) complexity.













#include <bits/stdc++.h>


int Solution::longestConsecutive(const vector<int> &A) {
    
   vector<int> v = A;
   sort(v.begin(),v.end());
   
   int cnt = 1;
   int ans = 1;
   for(int i=0;i<v.size();i++){
       if(v[i+1]==v[i]){
           continue;
       }
       if(v[i+1]-v[i]==1){
           cnt++;
       }
       else{
           ans = max(ans,cnt);
           cnt = 1;
       }
   }
   
   
   return ans;
}
