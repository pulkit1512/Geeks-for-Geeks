class Solution {
  public:
    void helper(int n,string temp,int count1,int count2,vector<string>&ans){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        if(count1>count2) return ;
        helper(n,temp+'1',count1,count2+1,ans);
        if(count1<count2){
        helper(n,temp+'0',count1+1,count2,ans);
        }
    }
    vector<string> NBitBinary(int n) {
        // Your code goes here
        vector<string>ans;
        helper(n,"",0,0,ans);
        return ans;
    }
};