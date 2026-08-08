class Solution {
  public:
    int maxWeightCell(vector<int> &exits) {
        // code here
        int n=exits.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(exits[i]!=-1){
                m[exits[i]]+=i;
            }
        }
        int ans=0;
        int maxi=INT_MIN;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>maxi){
                maxi=it->second;
                ans=it->first;
            }
        }
        return ans;
        
    }
};