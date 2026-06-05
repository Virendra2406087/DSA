class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
     bool same(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != b[i][j])
                    return false;
            }
        }

        return true;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int k = 0; k < 4; k++) {
            if (same(mat, target)){
                return true;
            }
            rotate(mat);
        }
        return false;
    }
};