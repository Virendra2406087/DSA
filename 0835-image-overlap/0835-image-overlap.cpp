class Solution {
public:
    int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B, int rowOff, int colOff) {
        int n = A.size();
        int count = 0;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(row+rowOff < 0 || row+rowOff >= n || col+colOff < 0 || col+colOff >= n){
                    continue;
                }
                count += A[row][col]*B[row+rowOff][col+colOff];
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int maxOverlap=0;
        for(int rowOff = -n+1; rowOff<n; rowOff++) {
            for(int collOff = -n+1; collOff<n; collOff++) {
                maxOverlap = max(maxOverlap, countOverlaps(img1, img2, rowOff, collOff));
            }
        }
        
        return maxOverlap;
    }
};