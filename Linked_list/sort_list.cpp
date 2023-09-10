// merge sort in linked list




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
 
 ListNode *merge(ListNode *l1,ListNode *l2){
     
     ListNode *dummy = new ListNode(-1);
     ListNode *p = dummy;
     while(l1 && l2){
         if(l1->val <= l2->val){
             p->next = l1;
             l1 = l1 ->next;
         }
         else{
             p->next = l2;
             l2 = l2->next;
         }
         
         p = p->next;
     }
     
     if(l1){
         p->next = l1;
     }
     
     if(l2){
         p->next = l2;
     }
     
     
     return dummy->next;
 } 
 
ListNode* Solution::sortList(ListNode* A) {
    
  // making part of linked list 
  // and then using merge sort to get the sortest list
  
  if( A == NULL || A->next == NULL) return A;
  ListNode *slow = A;
  ListNode *fast = A;
  
  // to store previous node just half node
  ListNode *prev = NULL;
  
  
  while(fast && fast->next){
      
      prev = slow;
      slow = slow ->next;
      fast = fast ->next ->next;
      
  }
  
  // now there are two linked lists
  prev->next = NULL;
  ListNode *l1 = sortList(A);
  ListNode *l2 = sortList(slow);
  
  ListNode *result = merge(l1,l2);
  
  return result;
  
}
