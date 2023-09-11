Insertion Sort List


Bookmarked
Asked In:
Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2








/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
void insertionSort(ListNode * &sorted,ListNode *newNode){
    
    if(sorted == NULL || sorted->val > newNode->val){
        newNode ->next = sorted;
        sorted = newNode;
        return;
    }
    
    // finding that node where this node can be pushed into
    ListNode *temp = sorted;
    
    while(temp -> next != NULL && temp->next->val <= newNode-> val){
        
        temp = temp->next;
    }
    
    // assigning node's text to greater node
    // and previous to this node
    newNode ->next = temp->next;
    temp ->next = newNode;
    
}


ListNode* Solution::insertionSortList(ListNode* A) {
    
    if(A->next == NULL) return A;
    
    ListNode *sortedList = NULL;
    
    ListNode *temp = A;
    
    // making list into sorted and unsorted
    
    while(temp){
        // traversing every element and pushed 
        // insto sorted List
        ListNode *forward = temp->next;
        
        insertionSort(sortedList,temp);
        
        temp = forward;
    }
    
    return sortedList;
}
