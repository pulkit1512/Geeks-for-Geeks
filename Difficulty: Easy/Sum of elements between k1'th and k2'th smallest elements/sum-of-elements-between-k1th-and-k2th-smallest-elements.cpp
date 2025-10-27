class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Your code goes here
        priority_queue<long long>pq1;
        priority_queue<long long>pq2;
        for(int i=0;i<N;i++){
            pq1.push(A[i]);
            if(pq1.size()>K1){
                pq1.pop();
            }
        }
        for(int i=0;i<N;i++){
            pq2.push(A[i]);
            if(pq2.size()>K2-1){
                pq2.pop();
            }
        }
        long long sum1=0,sum2=0;
        while(!pq1.empty()){
            sum1+=pq1.top();
            pq1.pop();
            
        }
        while(!pq2.empty()){
            sum2+=pq2.top();
            pq2.pop();
        }
        long long ans=sum2-sum1;
        return ans;
        
    }
};