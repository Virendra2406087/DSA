class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            int tempMax = max({curr, curr * maxProd, curr * minProd});
            int tempMin = min({curr, curr * maxProd, curr * minProd});

            maxProd = tempMax;
            minProd = tempMin;

            ans = max(ans, maxProd);
        }

        return ans;
    }
};