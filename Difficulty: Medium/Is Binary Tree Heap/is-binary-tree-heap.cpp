/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int count(Node*root){
        if(!root) return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool cbt(Node*root,int index,int total_nodes){
        if(!root) return 1; // leaf node is consider as cbt 
        if(index>=total_nodes) return 0;
        bool left=cbt(root->left,2*index+1,total_nodes);
        bool right=cbt(root->right,2*index+2,total_nodes);
        return left&&right;
    }
    bool maxHeap(Node*root){
        //left node exist
        if(root->left){
            if(root->left->data>root->data) return 0;
            if(!maxHeap(root->left)) return 0;
        }
        if(root->right){
            if(root->right->data>root->data) return 0;
             return maxHeap(root->right);
             //we directly return above becuse if the left is not max heap then it directly return 0 if it is then it depend on the right side 
             // so what right side is the answer so we return it directly
        }
        return 1;
        // return 1 for the leaf node 
    }
    bool isHeap(Node* tree) {
        // code here
        int num=count(tree);
        bool ans=cbt(tree,0,num);
        if(ans==0) return 0;
        return maxHeap(tree);
    }
};