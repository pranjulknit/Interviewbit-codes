// Reverse a linked list from position m to n. Do it in-place and in one-pass.

// For example:

// Given 1->2->3->4->5->NULL, m = 2 and n = 4,

// return 1->4->3->2->5->NULL.

// Note:

// Given m, n satisfy the following condition:

// 1 ≤ m ≤ n ≤ length of list.

// Note 2:

// Usually the version often seen in the interviews is reversing the whole linked list
//  which is obviously an easier version of this question.






/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
 
ListNode* reverse (ListNode *head){
    
    
    
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
 
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    
    if(B==C) return A;
   
   // reverse the part of the linked list
   
   int i=1;
   ListNode *prev=NULL,*revstart=NULL,*revend=NULL,*revend_next=NULL;
   
   ListNode *temp = A;
   
   while(temp != NULL && i<=C){
       
       if(i<B){
           prev = temp;
           
       }
       if(i==B){
           revstart = temp;
       }
       if(i==C){
           revend = temp;
           revend_next = temp->next;
       }
       i++;
       temp = temp->next;
   }
   
   // make revend's next  NULL;
   revend->next = NULL;
   
   // making reverse of sublist
   revend = reverse(revstart); 
   
   // if prev is NULL 
   if(prev)
   prev->next = revend;
   else{
       A = revend;
   }
   revstart->next = revend_next;
  
    
    return A;
}
