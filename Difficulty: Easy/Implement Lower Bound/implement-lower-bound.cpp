class Solution {
	public:
	int lowerBound(vector<int>& arr, int target) {
		// code here
		int ans = INT_MAX;
		int start = 0, end = arr.size() - 1;
		while (start <= end) {
			int mid = start + (end - start)/2;
			if (arr[mid] >= target) {
				ans = mid;
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		if(ans==INT_MAX) return arr.size();
		return ans;
	}
};
