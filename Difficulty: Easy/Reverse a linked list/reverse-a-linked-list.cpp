/*
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};
*/

/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node*curr=head;
        Node*prev=NULL;
     while(curr){
         Node*temp=curr->next;
         curr->next=prev;
         prev=curr;
         curr=temp;
     }
     return prev;
    }
};