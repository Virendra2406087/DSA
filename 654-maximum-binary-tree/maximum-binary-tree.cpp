/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> getmax(vector<int>& nums, int s, int e){
        if(s > e){
            return {INT_MIN, -1};
        }

        int maxi = INT_MIN;
        int index = s;

        while(s <= e){
            if(nums[s] > maxi){
                maxi = nums[s];
                index = s;
            }
            s++;
        }
        return {maxi, index};
    }
    TreeNode* solve(vector<int>& nums, int s, int e){
        if(s > e){
            return nullptr;
        }

        auto p = getmax(nums, s, e);
        int val = p.first;
        int idx = p.second;

        TreeNode* root = new TreeNode(val);
        root->left = solve(nums, s, idx - 1);
        root->right = solve(nums, idx + 1, e);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,0,n-1);
    }
};