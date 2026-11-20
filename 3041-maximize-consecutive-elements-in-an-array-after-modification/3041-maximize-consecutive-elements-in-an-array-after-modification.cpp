class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int findMethod(vector<int>& nums, int start, int target) {
        int j = lower_bound(begin(nums) + start, end(nums), target) - begin(nums);

        if(j < n && nums[j] == target) {
            return j;
        }

        return -1;
    }

    int solve(int i, int inc, vector<int>& nums) {

        if(memo[i][inc] != -1) {
            return memo[i][inc];
        }

        int currVal = nums[i] + inc; //inc = 0/1
        int len = 1;

        //1st Option = find (currVal+1)
        int j = findMethod(nums, i+1, currVal+1);
        if(j != -1) {
            len = max(len, 1 + solve(j, 0, nums));
        }

        //2nd Option = find (currVal) and then inc by +1
        j = findMethod(nums, i+1, currVal);
        if(j != -1) {
            len = max(len, 1 + solve(j, 1, nums));
        }

        return memo[i][inc] = len;
    }

    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();

        sort(begin(nums), end(nums));

        memo.assign(n+1, vector<int>(2, -1));

        int result = 1;
        for(int i = 0; i < n; i++) {
            result = max({result, solve(i, 0, nums), solve(i, 1, nums)});
        }

        return result;
    }
};