class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        long smallest=LONG_MAX;
        long sum=0;
        long count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<0){
                    count++;
                }
                long val=abs(matrix[i][j]);
                smallest=min(smallest,val);
                sum=sum+val;
            }
        }
        if(count%2==0){
            return sum;
        }
        return sum-2*smallest;
    }
};