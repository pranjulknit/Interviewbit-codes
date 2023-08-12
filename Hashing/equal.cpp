// Problem Description
 
 

// Given an array A of N integers, find the index of values 
// that satisfy P + Q = R + S, where P, Q, R & S are integers values in the array

// Expected time complexity O(N2)

// NOTE:
// 1) Return the indices A1 B1 C1 D1, so that 
//   A[A1] + A[B1] = A[C1] + A[D1]
//   A1 < B1, C1 < D1
//   A1 < C1, B1 != D1, B1 != C1 
// 2) If there are more than one solutions,
//    then return the tuple of values which are lexicographical smallest. 

// Assume we have two solutions
// S1 : A1 B1 C1 D1 ( these are values of indices in the array )
// S2 : A2 B2 C2 D2

// S1 is lexicographically smaller than S2 if:
//   A1 < A2 OR
//   A1 = A2 AND B1 < B2 OR
//   A1 = A2 AND B1 = B2 AND C1 < C2 OR 
//   A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
// If no solution is possible, return an empty list.


// Problem Constraints
// 1 <= N <= 1000

// 0 <= A[i] <= 1000



// Input Format
// First and only argument is an integer array A of length N.



// Output Format
// Return an array of size four which contains indices of values P, Q, R, and S.



// Example Input
// Input 1:

//  A = [3, 4, 7, 1, 2, 9, 8]
// Input 2:

//  A = [2, 5, 1, 6]


// Example Output
// Output 1:

//  [0, 2, 3, 5]
// Output 2:

//  [0, 1, 2, 3]









vector<int> Solution::equal(vector<int> &A) {
    
    //storing sum value as key and pair as their indexes
    map<int,pair<int,int>> mp;
    // storing all quadruples
    vector<vector<int>> ans;
    
    for(int i=0;i<A.size();i++){
        
        for(int j=i+1;j<A.size();j++){
            int sum = A[i]+A[j];
            pair<int,int> p = make_pair(i,j);
            

            // sum doesn't exist assign index pair
            if(!mp.count(sum)){
                mp[sum]=p;
            }
            else{

                // if sum exist check are they duplicate or not 
                set<int> st;
                st.insert(mp[sum].first);
                st.insert(mp[sum].second);
                st.insert(i);
                st.insert(j);
                

                // if unique values put in ans vector
                if(st.size()==4){
                    ans.push_back({mp[sum].first,mp[sum].second,i,j});
                }
            }
            
        }
        
        
    }
    

    // for lexicographically sort ans
    
    sort(ans.begin(),ans.end());
        
        if(ans.size()>0){
            return ans[0];
        }
        
        
        return {};
}
