class Solution {
  public:
    int minOperations(int arr[], int n, int k) {
        // code here
        priority_queue<int ,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        int ans=0;
        while(pq.top()<k&&pq.size()>1){
            int temp=pq.top();
            pq.pop();
            temp+=pq.top();
            pq.pop();
            if(temp!=0) pq.push(temp);
            ans++;
            
        }
        if(pq.top()<k) return -1;
        return ans;
    }
};