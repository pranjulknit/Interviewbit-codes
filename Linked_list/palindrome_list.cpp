/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *reverse(ListNode *head){
    
    ListNode *prev = NULL;
    ListNode *curr = head;
    
    while(curr != NULL){
        ListNode *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    
    
    return prev;
} 

int Solution::lPalin(ListNode* A) {
    
   ListNode *temp = A;
   vector<int> check;
   while(temp != NULL){
       check.push_back(temp->val);
       temp = temp->next;
   }
   
   int i = 0;
   int j= check.size()-1;
   
   while(i<=j){
       if(check[i]!=check[j]){
          return 0;
       }
       
        i++,j--;
   }
    return 1;
}
