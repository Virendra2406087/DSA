class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>ans(num_people,0);
        int candie=1;
        int index=0;
        while(candies > 0){
            int give = min(candies, candie);
            ans[index % num_people] += give;
            candies -= give;
            candie++;
            index++;
        }
        return ans;
    }
};