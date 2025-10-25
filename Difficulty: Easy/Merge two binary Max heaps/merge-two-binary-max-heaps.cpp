class Solution {
  public:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        for (int i = 0; i < n; ++i) ans.push_back(a[i]);
        for (int i = 0; i < m; ++i) ans.push_back(b[i]);

        n = ans.size();
        for (int i = n / 2 - 1; i >= 0; --i) {
            heapify(ans, n, i);
        }

        return ans;
    }
};
