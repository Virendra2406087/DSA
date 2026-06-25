#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                nums[i]=1;
            }else{
                nums[i]=-1;
            }
        }
        ordered_set<int>os;
        os.insert(0);
        long long ans=0;
        int prefix=0;
        for(int x:nums){
            prefix+=x;
            ans+=os.order_of_key(prefix);
            os.insert(prefix);
        }
        return ans;
    }
};