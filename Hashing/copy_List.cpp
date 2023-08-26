// A linked list is given such that each node contains an additional random
//  pointer which could point to any node in the list or NULL.

// Return a deep copy of the list.

// Example

// Given list

//    1 -> 2 -> 3
// with random pointers going from

//   1 -> 3
//   2 -> 1
//   3 -> 1
// You should return a deep copy of the list. The returned answer should
//  not contain the same node as the original list, but a copy of them. 
//  The pointers in the returned list should not link to any node in the 
//  original input list.






/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {

    //making deep copy of a list
    
   RandomListNode *temp1 = A;
   
   // dummy node
   RandomListNode *dummyNode = new RandomListNode(-1);
   
   // this pointer to dummyNode
   RandomListNode *temp2 = dummyNode;
   
   // map for this node makes which node
   // like a node making a'
   // b node making b'
   
   map<RandomListNode*,RandomListNode*> mp;
   
   // making just next pointer clone
   
   while(temp1 != NULL){
       RandomListNode * node = new RandomListNode(temp1->label);
       
       // add this node to dummy node
       temp2->next = node;
       //storing mp[a] = 'a,mp[b] = 'b
       mp[temp1] = node;
       
       temp1 = temp1->next;
       temp2 = temp2->next;
   }
   
   temp1 = A;
   temp2 = dummyNode->next;
   
   while(temp1 != NULL){
       RandomListNode *node = temp1->random;
       
       temp2->random = mp[node];
       
       temp1 = temp1->next;
       temp2 = temp2->next;
   }
   
   
   return dummyNode->next;
    
}
