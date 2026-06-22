class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int area=0;
        int start=0,end=height.size()-1;
        while(start<=end){
            area=max(area,min(height[start],height[end])*(end-start-1));
            if(height[start]>height[end]) end--;
            else start++;
           
        }
        return area;
    }
};