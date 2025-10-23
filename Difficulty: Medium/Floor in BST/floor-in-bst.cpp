// Function to search a node in BST.
class Solution {

  public:
    void helper(Node*root,int x,int&ans){
        if(!root) return ;
        if(root->data<=x){ 
            ans=root->data;
            helper(root->right,x,ans);

        }
        else{
            helper(root->left,x,ans);
        }
        
    }
    
    int floor(Node* root, int x) {
        // Code here
        int ans=-1;
        helper(root,x,ans);
        return ans;
    }
};