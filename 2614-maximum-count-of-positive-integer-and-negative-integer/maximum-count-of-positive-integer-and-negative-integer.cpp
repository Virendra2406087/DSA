class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;
        int firstNonNegative = n;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] >= 0) {
                firstNonNegative = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        
        int negCount = firstNonNegative;
        s = 0, e = n - 1;
        int firstPositive = n;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] > 0) {
                firstPositive = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        
        int posCount = n - firstPositive;
        
        return max(negCount, posCount);
    }
};