class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        vector<int>arr(26,0);
        for(int i=0;i<s.size();i++){
             arr[s[i]-'a']++;
        }
        char ans ;
        int count=INT_MIN;
        for(int i=0;i<26;i++){
            if(count<arr[i]){
                count=arr[i];
                ans=i+'a';
            }
        }
        return ans;
    }
};