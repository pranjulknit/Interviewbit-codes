/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
      ListNode *temp = A;
    
    // In leetcode corner test case missed.
    // where B> total length of list
    
    // logic is since distance between two pointer will be consatant
    // so in first move move first pointer to 
    // B steps;
    while(B && temp){
        temp = temp->next;
        B-=1;
    }
    
    
    //ListNode *dum = new ListNode(-1);
    if(temp == NULL || B>0){
        return A->next;
    }
    
    
    ListNode *slow = A;
    
    while(temp->next){
        slow = slow->next;
        temp = temp->next;
        
    }
    ListNode *p= slow->next;
    
    slow->next = p->next;
    delete(p);
    //cout<<slow->next->val<<endl;
    
    return A;
        
}
