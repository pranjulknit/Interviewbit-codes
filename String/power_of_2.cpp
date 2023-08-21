// Problem Description
 
 

// Find if the given number is a power of 2 or not. More specifically, find if the given number can be expressed as 2^k where k >= 1.
// Note: The number length can be more than 64, which means the number can be greater than 2 ^ 64 (out of long long range)


// Problem Constraints
// 1 <= |A| <= 104


// Input Format
// The first argument is a string A.


// Output Format
// Return 1 if the number is a power of 2 else return 0


// Example Input
// 128


// Example Output
// 1






int Solution::power(string A) {
    
   
    //logic just check the multiple of 2
    
    
     string temp="2";
     
     while(1){
        
         if(temp.size()>A.size()) break;
         if(temp == A)   return 1;
         
         int carry = 0;
         int n = temp.size();
         string check;
         for(int i=n-1;i>=0;i--){
             
             int sum  = (temp[i]-'0')*2;
             
             sum += carry;
             
             carry = sum/10;
             
             check.push_back((sum%10 )+'0');
         }
         
         if(carry){
             check.push_back('0'+carry%10);
           
         }
         
         
         reverse(check.begin(),check.end());
         temp = check;
         
       // cout<<temp<<endl;
         
     }
     
     
     return 0;
}


