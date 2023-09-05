// Given a sorted linked list, delete all duplicates such that each 
// element appear only once.

// For example,

// Given 1->1->2, return 1->2.

// Given 1->1->2->3->3, return 1->2->3.





/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    // using pointer
    // if next value equals to previous delete next and forward to next node
    
  
    ListNode *temp = A;
    
    
    while(temp->next){
        if(temp->val == temp->next->val){
            
            ListNode *forward = temp->next->next;
            //delete(temp->next);
            
            temp->next= forward;
        }
        else{
       
        temp = temp->next;
        }
        
       
    }
    
    
    return A;
    
    
}
