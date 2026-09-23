class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int totalSum = 0;

        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        int target = totalSum - x;

        if(target < 0) {
            return -1;
        }

        // If we have to remove everything
        if(target == 0) {
            return n;
        }

        int left = 0;
        int sum = 0;
        int maxLength = -1;

        for(int right = 0; right < n; right++) {
            sum += nums[right];

            while(sum > target && left <= right) {
                sum -= nums[left];
                left++;
            }

            if(sum == target) {
                maxLength = max(maxLength, right - left + 1);
            }
        }

        if(maxLength == -1) {
            return -1;
        }

        return n - maxLength;
    }
};