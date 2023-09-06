/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    
    if(A == NULL) return NULL;
    
    
    //reversing only k elements
    // rest done by recursion
    ListNode *prev = NULL;
    ListNode *curr = A;
    
    for(int i=0;i<B;i++){
        
        ListNode* forward = curr->next;
        
        curr->next = prev;
        prev = curr;
        
        curr = forward;
        
    }
    
    // now current node become forward node
    
    // if(curr != NULL){
        
        A->next = reverseList(curr,B);
   // }
    
    return prev;
}
