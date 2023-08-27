

bool comp(string &a,string &b){
    
    // for(int i=0;i<min(a.size(),b.size());i++){
        
    //     if(a[i] != b[i]){
    //         return a[i]<b[i];
    //     }
    // }
    
    
    // return a.size()<b.size();
    
    
     int idx1 = a.find('-');
       int idx2 = b.find('-');


       string s1 = a.substr(idx1+1);
       string s2 = b.substr(idx2+1);

       if(s1!=s2){
           return s1<s2;
       }



       return a<b;
}



vector<string> Solution::reorderLogs(vector<string> &A) {
    
    // make seprate string for letter letterlog
    // and digit llog
    vector<string> letterlog;
    vector<string> digitlog;
    
    
    for(auto s:A){
        // if after first space 
        // there is char then it is 
        // letter log else digit log
        int idx = s.find('-');
        
        if(s[idx+1] >= 'a' && s[idx+1]<='z'){
            letterlog.push_back(s);
        }
        else{
            digitlog.push_back(s);
        }
    }
    
    
    sort(letterlog.begin(),letterlog.end(),comp);
    
    vector<string> ans;
    
    for(auto s:letterlog){
        ans.push_back(s);
    }
    
    for(auto s:digitlog){
        ans.push_back(s);
    }
    
    
    
    return ans;
}
