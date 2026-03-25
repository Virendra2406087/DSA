class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> sums = mat[0];

        for (int i = 1; i < mat.size(); i++) {
            priority_queue<int> pq; 

            for (int a : sums) {
                for (int b : mat[i]) {
                    int s = a + b;

                    if (pq.size() < k) {
                        pq.push(s);
                    } else if (s < pq.top()) {
                        pq.pop();
                        pq.push(s);
                    }
                }
            }

            sums.clear();
            while (!pq.empty()) {
                sums.push_back(pq.top());
                pq.pop();
            }
        }

        return *max_element(sums.begin(), sums.end());
    }
};