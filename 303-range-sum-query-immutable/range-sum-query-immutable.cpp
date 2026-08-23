class NumArray {
public:
    vector<int>segment;
    int n;
    void build(vector<int>&nums,int i,int l,int r){
        if(l==r){
            segment[i]=nums[r];
            return;
        }
        int mid=(l+r)/2;
        build(nums,2*i+1,l,mid);
        build(nums,2*i+2,mid+1,r);
        segment[i]=segment[2*i+1]+segment[2*i+2];
    }
    int Query(int start,int end,int i,int l,int r){
        if(l>end || r<start){
            return 0;
           }        
           if(l>=start && r<=end){
            return segment[i];
           }
           int mid=l+(r-l)/2;
           return Query(start,end,2*i+1,l,mid)+Query(start,end,2*i+2,mid+1,r);
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
       if(n>0){
        segment.resize(4*n);
        build(nums,0,0,n-1);
       }
    }
    
    int sumRange(int left, int right) {
           if(n==0){
            return 0;
           }
           return Query(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */