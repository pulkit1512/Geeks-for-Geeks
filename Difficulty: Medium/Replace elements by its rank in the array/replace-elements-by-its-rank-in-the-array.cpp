class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        vector<int> uniqueSorted;
        // remove duplicates
        uniqueSorted.push_back(sortedArr[0]);
        for (int i = 1; i < N; i++) {
            if (sortedArr[i] != sortedArr[i - 1]) {
                uniqueSorted.push_back(sortedArr[i]);
            }
        }

        vector<int> ans(N);
        for (int i = 0; i < N; i++) {
            int left = 0, right = uniqueSorted.size() - 1, rank = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (uniqueSorted[mid] == arr[i]) {
                    rank = mid;
                    right = mid - 1;
                } else if (uniqueSorted[mid] < arr[i]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            ans[i] = rank+1;
        }

        return ans;
    }
};
