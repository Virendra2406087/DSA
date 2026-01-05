#include <vector>
using namespace std;

class Solution {
public:
    vector<int> ans;
    vector<pair<int,int>> arr;  // {value, original index}

    // Your merge function stays the same logically
    void merge(vector<pair<int,int>>& arr, int s, int e, int mid) {
        int leftArray = mid - s + 1;
        int rightArray = e - mid;

        vector<pair<int,int>> left(leftArray);
        vector<pair<int,int>> right(rightArray);

        int mainArray = s;
        for(int i = 0; i < leftArray; i++)
            left[i] = arr[mainArray++];

        mainArray = mid + 1;
        for(int i = 0; i < rightArray; i++)
            right[i] = arr[mainArray++];

        int i = 0, j = 0;
        mainArray = s;
        int rightCount = 0; // count of right elements moved

        while(i < leftArray && j < rightArray){
            if(left[i].first <= right[j].first){
                ans[left[i].second] += rightCount;
                arr[mainArray++] = left[i++];
            }else{
                rightCount++;
                arr[mainArray++] = right[j++];
            }
        }

        while(i < leftArray){
            ans[left[i].second] += rightCount;
            arr[mainArray++] = left[i++];
        }

        while(j < rightArray){
            arr[mainArray++] = right[j++];
        }
    }

    void mergeSorted(vector<pair<int,int>>& arr, int s, int e){
        if(s >= e) return;
        int mid = s + (e - s)/2;
        mergeSorted(arr, s, mid);
        mergeSorted(arr, mid+1, e);
        merge(arr, s, e, mid);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.assign(n, 0);
        arr.clear();

        for(int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        mergeSorted(arr, 0, n-1);
        return ans;
    }
};
