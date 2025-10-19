class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int ans;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        for(int i=0;i<k-1;i++){
            pq.pop();
            
        }
        ans=pq.top();
        return ans;
    }
};