
class Solution {
  public:
    int countNumberswith4(int n) {
        int ans = 0;
        for (int i = 4; i <= n; ++i) {
            string str = to_string(i);
            if (str.find('4')!=string::npos) ++ans;
        }
        
        return ans;
    }
};
