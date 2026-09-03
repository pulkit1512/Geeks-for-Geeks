class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>prefix;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            prefix.push_back(sum);
        }
        unordered_map<int,int>m;
        m[0]++;
        int total=0;
        for(int i=0;i<n;i++){
           
            
            if(m[prefix[i]]==0){
                m[prefix[i]]++;
            }
            else{
                total+=m[prefix[i]];
                m[prefix[i]]++;
            }
        }
        return total;
    }
};