class Solution {
  public:
    void helper(stack<int>&st,int x){
        if(st.empty() || st.top()<x){
            st.push(x);
            return ;
        }
        int temp=st.top();
        st.pop();
        helper(st,x);
        st.push(temp);
    }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()) return ;
        int x=st.top();
        st.pop();
        sortStack(st);
        helper(st,x);
        
    }
};
