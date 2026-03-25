class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long totalSum = 0;
        int s = 0, e = nums.size() - 1;

        while (s <= e) {
            if (s == e) {
                totalSum += nums[s];
            } else {
                int temp = nums[e];
                int multiplier = 1;
                while (temp > 0) {
                    multiplier *= 10;
                    temp /= 10;
                }

                long long sum = (long long)nums[s] * multiplier + nums[e];
                totalSum += sum;
            }
            s++;
            e--;
        }

        return totalSum;
    }
};