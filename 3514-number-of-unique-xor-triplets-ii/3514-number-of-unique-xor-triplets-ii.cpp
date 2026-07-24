class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int maxXor = 2048;

        vector<bool> pairXor(maxXor, false);
        vector<bool> tripletXor(maxXor, false);

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor[nums[i] ^ nums[j]] = true;
            }
        }

        for (int x = 0; x < maxXor; x++) {
            if (!pairXor[x]) continue;
            for (int v : nums) {
                tripletXor[x ^ v] = true;
            }
        }

        int count = 0;
        for(int i = 0; i < maxXor; i++){
            if(tripletXor[i]) count++;
        }

        return count;
    }
};