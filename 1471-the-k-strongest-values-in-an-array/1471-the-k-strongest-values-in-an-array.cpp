class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int m = arr[(n - 1) / 2]; 

        int l = 0, r = n - 1;
        vector<int> ans;

        while (k--) {
            if (abs(arr[r] - m) > abs(arr[l] - m)) {
                ans.push_back(arr[r--]);
            } else if (abs(arr[r] - m) < abs(arr[l] - m)) {
                ans.push_back(arr[l++]);
            } else {
                ans.push_back(arr[r--]);
            }
        }
        return ans;
    }
};
