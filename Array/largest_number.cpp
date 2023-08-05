




// Given a list of non-negative integers, arrange them such that 
// they form the largest number.

// Example Input
// A = [3, 30, 34, 5, 9]

// 9534330















//comparator for checking whether "30" "9" 
// "309" is greater or "930"


bool comp(string x,string y){
    string check1 = x+y;
    string check2 = y+x;
    
    return check1>check2;
}


string Solution::largestNumber(const vector<int> &A) {
    
    vector<string> temp;
    
    for(int i=0;i<A.size();i++){
        //element to string
        temp.push_back(to_string(A[i]));
    }
    
    sort(temp.begin(),temp.end(),comp);
    
    string ans="";
    for(int i=0;i<temp.size();i++){
        ans += temp[i];
    }
    
    int i =0;
    
    // that every element not zero
    // corner case "000000000"
    while(ans[i]=='0'){
        i++;
    }
    
    if(i==ans.size()){
        ans = "0";
    }
    
    
    return ans;
}

