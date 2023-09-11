Problem Description
 
 

Given a list, rotate the list to the right by k places, where k is non-negative.


Problem Constraints
1 <= B <= 109


Input Format
The first argument is ListNode A, pointing to the head of the list.
The second argument is an integer B, representing the value of k.


Output Format
Return the rotated list.


Example Input
A = 1->2->3->4->5->NULL
B = 2


Example Output
4->5->1->2->3->NULL


Example Explanation
Given list: A = 1->2->3->4->5->NULL
Given B = 2;
After rotating A once, A = 5->1->2->3->4->NULL
After rotating A again, A = 4->5->1->2->3->NULL
Hence after rotating the given list A, for B = 2, return 4->5->1->2->3->NULL







/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 

ListNode* Solution::rotateRight(ListNode* A, int B) {
    
    // making two Lists 
    // then combined into to head of linked listt
    
    if(A->next == NULL ) return A;
    
    
    
    ListNode *l2 = NULL;
    // size of the linked list
    int cnt = 0;
    
    ListNode *temp = A;
    
    while(temp){
        cnt++;
        
        temp = temp->next;
    }
    
    // traverse loop only n-b times
    
    
    B %= cnt;  // if B > cnt;
    cnt-=B;
    
    // if B is divisble or cnt<=0
    if(cnt<=0 or B== 0) return A;
    ListNode *prev = NULL;
    
    temp = A;
    for(int i=0;i<cnt;i++){
        prev = temp;
        temp = temp->next;
        
    }
    
    // assigning previous node to null;
    
   
    prev-> next = NULL;
    
    // second list 
    
    l2 = temp;
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = A;
    
    return l2;
}
