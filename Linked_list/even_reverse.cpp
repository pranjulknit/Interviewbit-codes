
// reverse the node at even posiotion



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
    
    while(curr){
        ListNode *forward = curr ->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        
    }
    
    
    return prev;
}
 
ListNode* Solution::solve(ListNode* A) {
    
    if(A->next == NULL) return A;
    ListNode *temp = A;
   ListNode *odd = A;
   ListNode *eve = A->next;
   
   ListNode *dummy= new ListNode (-1);
   ListNode *p = dummy;
   
   // collecting even node in dummy list;
   while(eve && eve->next){
       
       // temporary stroing even node
      
      ListNode *t = eve;
      
      odd ->next = eve -> next;
      
      odd = eve->next;
      eve = eve->next->next;
      
      t->next = NULL;
      p->next = t;
      
      p = p->next;
      
      // if last element is even position
      if(eve != NULL && eve->next == NULL){
          ListNode *t = eve;
          odd->next = NULL;
          p->next = t;
      }
       
   }
   
   // combining odd and even list
    eve = reverse(dummy);
    odd = A;
   while(odd){
       
     ListNode *node1 = eve;
     ListNode *node2 = odd;
     
     // if at the end of even node
     if(node1->val == -1) break;
     
     eve = eve->next;
     odd = odd->next;
     
     
     node1->next = NULL;
     node2->next = node1;
     node1->next = odd;
     
     
       
   }
    
    return A;
}
