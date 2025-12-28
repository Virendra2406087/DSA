class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startingRow=0;
        int startingCol=0;
        int n=matrix.size();
        int m=matrix[0].size();
        int endingRow=n-1;
        int endingCol=m-1;
        vector<int>ans;
        while(startingRow<=endingRow && startingCol<=endingCol){
        for(int col=startingCol;col<=endingCol;col++){
            ans.push_back(matrix[startingRow][col]);
        }
        startingRow++;
        for(int row=startingRow;row<=endingRow;row++){
            ans.push_back(matrix[row][endingCol]);
        }
        endingCol--;
        if(startingRow<=endingRow){
           for(int col=endingCol;col>=startingCol;col--){
              ans.push_back(matrix[endingRow][col]);
           }
        endingRow--;
        }

        if(startingCol<=endingCol){
          for(int row=endingRow;row>=startingRow;row--){
               ans.push_back(matrix[row][startingCol]);
           }
        startingCol++;

        }
        }
       return ans;
    }
};