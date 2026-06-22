class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        queue<int>q;
        while(!st.empty()){
            int temp=st.top();
            st.pop();
            q.push(temp);
        }
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            st.push(temp);
        }
        
    }
};