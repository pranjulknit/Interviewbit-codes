
Problem Description

Given a linked list A of length N and an integer B.

You need to reverse every alternate B nodes in the linked list A.



Problem Constraints
1 <= N <= 105
1<= Value in Each Link List Node <= 103
1 <= B <= N
N is divisible by B


Input Format
First argument is the head pointer of the linkedlist A.

Second argument is an integer B.



Output Format
Return the head pointer of the final linkedlist as described.



Example Input
Input 1:

 A = 3 -> 4 -> 7 -> 5 -> 6 -> 6 -> 15 -> 61 -> 16
 B = 3
 Input 2:

 A = 1 -> 4 -> 6 -> 6 -> 4 -> 10
 B = 2


Example Output
Output 1:

 7 -> 4 -> 3 -> 5 -> 6 -> 6 -> 16 -> 61 -> 15
Output 2:

 4 -> 1 -> 6 -> 6 -> 10 -> 4


Example Explanation
Explanation 1:

 The linked list contains 9 nodes and we need to reverse alternate 3 nodes.
 First sublist of length 3  is 3 -> 4 -> 7 so on reversing it we get 7 -> 4 -> 3.
 Second sublist of length 3 is 5 -> 6 -> 6 we don't need to reverse it.
 Third sublist of length 3 is 15 -> 61 -> 16 so on reversing 
 it we get 16 -> 61 -> 15.
Explanation 2:

 The linked list contains 6 nodes and we need to reverse alternate 2 nodes.
 First sublist of length 2 is 1 -> 4 so on reversing it we get 4 -> 1.
 Second sublist of length 2 is 6 -> 6 we don't need to reverse it.
 Third sublist of length 2 is 4 -> 10 so on reversing it we get 10 -> 4.














/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *rec(ListNode *A,int B,int x){
    //if( A== NULL) return A;
    
    ListNode *prev = NULL;
    ListNode *curr = A;
    
    if(x%2==0){
        
        for(int i=0;i<B ;i++){
            ListNode *forward = curr->next;
            
            curr ->next = prev;
            
            prev = curr;
            
            curr = forward;
            
            
        }
    }
    else{
        // when we don't have to reverse
        
        // storing prev node which will linked to node
        prev = curr;
        
        // mvoing A Node till B-1 position which will be just behind that node
        for(int i=0;i<B-1 && A!= NULL;i++){
          A = A->next;
           
            
        }
        // since curr will be 1step ahead of A
        curr = A->next;
    }
    
    x++;
    if(curr!=NULL)
    A ->next = rec(curr,B,x);
    
    return prev;
}
ListNode* Solution::solve(ListNode* A, int B) {
    
    
    
    // reversing k node with 
   ListNode *result =  rec(A,B,0);
   
   
   return result;
}
