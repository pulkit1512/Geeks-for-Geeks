class Solution {
  public:
    void merge(vector<int>&arr,int start,int end,int mid,int &ans){
        int j=mid+1;
        for(int i=start;i<=mid;i++){
            // this is 0(n) not n square becuse we are not reset the j after each iteration
            while(j<=end&&arr[i]>arr[j]){
                j++;
            }
            ans+=j-(mid+1);// how many times a j is increment there are thau number of inversions
        }
        vector<int>temp;
        int left=start,right=mid+1;
        while(left<mid+1&&right<end+1){
            if(arr[left]>arr[right]){
                temp.push_back(arr[right++]);
            } else{
                temp.push_back(arr[left++]);
            }
        }
        while(left<=mid){
            temp.push_back(arr[left++]);
        }
        while(right<=end){
            temp.push_back(arr[right++]);
        }
         for (int i = start; i <= end; ++i) {
            arr[i] = temp[i - start];
        }
    }
    void dc(vector<int>&arr,int start,int end,int&ans){
        if(start>=end) return ;
        int mid =start+(end-start)/2;
        dc(arr,start,mid,ans);
        dc(arr,mid+1,end,ans);
        merge(arr,start,end,mid,ans);
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        // same as a reverse pair question of a leetcode
        int ans=0;
        int n=arr.size();
        dc(arr,0,n-1,ans);
        return ans;
    }
};