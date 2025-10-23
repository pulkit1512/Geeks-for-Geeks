/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        if(!head){
            return new Node(x);
        }
        Node*previ=NULL;
        Node*temp=head;
        for(int i=0;i<p+1;i++){
            previ=temp;
            temp=temp->next;
            
        }
        Node* temp2=new Node(x);
        previ->next=temp2;
        temp2->prev=previ;
        temp2->next=temp;
        if(temp){
            temp->prev=temp2;
        }
        return head;
        
    }
};