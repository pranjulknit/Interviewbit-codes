/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    
    
    
    // using slow and fast pointer approach
    
    ListNode *slow = A;
    ListNode *fast = A;
    
    while(fast && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            break;
        }
    }
    
    if(fast == NULL or fast->next == NULL)  return NULL;
    
    // if cycle is there then slow and fast will meet at some point
    // so starting from 0th postion again
    // wherever pointer will meet that is the 
    // first meeting point
    ListNode *ptr1 = slow;
    ListNode *ptr2 = A;
    
    
    while(ptr1 != ptr2){
        ptr1 = ptr1->next;
        
        ptr2 = ptr2->next;
    }
    
    
    return ptr1;
}
