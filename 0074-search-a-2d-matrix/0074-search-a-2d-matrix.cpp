class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(matrix[row][col]==target){
                    return true;
                }
            }
        }
        return false;
    }
};