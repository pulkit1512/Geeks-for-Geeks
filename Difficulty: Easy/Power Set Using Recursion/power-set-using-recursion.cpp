class Solution {
  public:
    void helper(string s ,int i,string s1,vector<string>&ans){
        if(i==s.size()){
            ans.push_back(s1);
            return;
        }
        helper(s,i+1,s1+s[i],ans);
        
        helper(s,i+1,s1,ans);
    }
    vector<string> powerSet(string s) {
        // code here
        vector<string> ans;
        int i=0;
        helper(s,i,"",ans);
        return ans;
    }
};
