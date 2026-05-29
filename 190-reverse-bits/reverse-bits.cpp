class Solution {
public:
    int reverseBits(int n) {

        vector<int> binary;

        while(n != 0) {
            binary.push_back(n % 2);
            n = n / 2;
        }

        while(binary.size() < 32)
            binary.push_back(0);

        reverse(binary.begin(), binary.end());

        int value = 0;

        for(int i = 0; i < 32; i++) {
            value += binary[i] * (1 << i);
        }

        return value;
    }
};