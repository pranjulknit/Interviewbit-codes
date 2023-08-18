// 









bool isValid(string s1,string s2,string s3,string s4){

    // valid function to check the string is valid or not

    int size1 = s1.size();
    int size2 = s2.size();
    int size3 = s3.size();
    int size4 = s4.size();

    // if any of the size is 0 return false
    
    if(size1 == 0 || size2 == 0 ||  size3 == 0 ||  size4 ==0 ){
        return false;
    }
    
    int  num1 = stoi(s1);
    int  num2 = stoi(s2);
    int  num3 = stoi(s3);
    int  num4 = stoi(s4);
    
    // there number shoud be between 0>=255
    if(num1 >= 0 && num2 >= 0  && num3 >= 0 && num4 >= 0 && num1<=255 && num2<=255 && num3<=255 && num4<=255){
        
        // if any has trailing zeroes
        if(to_string(num1) != s1 || to_string(num2) != s2 || to_string(num3) != s3 || to_string(num4) != s4){
            return false;
        }
        
        return true;
    }
    
    return false;
}




vector<string> Solution::restoreIpAddresses(string A) {
    
    
    
    vector<string> ans;
    int n  = A.size();

    // bruteforcing all strings
    for(int i=1;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=j;k<n;k++){
                
                string s1 = A.substr(0,i);
                string s2 = A.substr(i,j-i);
                string s3 = A.substr(j,k-j);
                string s4 = A.substr(k);
                
                if(isValid(s1,s2,s3,s4)){
                   ans.push_back(s1+"."+s2+"."+s3+"."+s4); 
                }
            }
        }
    }
    
    
    return ans;
}
