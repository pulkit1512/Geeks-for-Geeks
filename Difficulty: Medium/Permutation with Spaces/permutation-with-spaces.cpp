class Solution {
  public:
      void dfs(string &s, int i, int n, vector<string>& ans, string temp) {
          if (i == n) {
              ans.push_back(temp); 
              return;
          }
          
          dfs(s, i + 1, n, ans, temp + s[i]);
          if(i!=0){
          dfs(s, i + 1, n, ans, temp + " " + s[i]);
          }
      }

      vector<string> permutation(string s) {
          vector<string> ans;
          int n = s.length();
          if (n == 0) return ans;
          
          string temp = "";
          
          dfs(s, 0, n, ans, temp);

          sort(ans.begin(), ans.end());
          return ans;
      }
  };