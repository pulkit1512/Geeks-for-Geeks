class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        int ans=-1;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>arr.size()/2){
                ans=it->first;
                break;
            }
        }
        return ans;
    }
};