class Info{
    public:
    int data;
    int rIndex;
    int cIndex;
    Info(int val,int r,int c){
        data=val;
        rIndex=r;
        cIndex=c;
    }
};
class Compare{
    public:
    bool operator()(Info* a ,Info* b){
        return a->data>b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*,vector<Info*>,Compare>pq;
        vector<int>ans;
        int rows=nums.size();
        int columns=nums[0].size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<rows;i++){
            int element=nums[i][0];
            Info* temp=new Info(element,i,0);
            pq.push(temp);
            mini=min(mini,element);
            maxi=max(maxi,element);
        }
        int ansStart=mini;
        int ansEnd=maxi;
        while(!pq.empty()){
            Info* front=pq.top();
            pq.pop();
            int element=front->data;
            int rowIndex=front->rIndex;
            int colIndex=front->cIndex;
            mini=element;
            if((maxi-mini)<(ansEnd-ansStart)){
                ansStart=mini;
                ansEnd=maxi;
            }
            int totalColumn=nums[rowIndex].size();
            if(colIndex+1 < totalColumn){
                int element=nums[rowIndex][colIndex+1];
                Info* temp=new Info(element,rowIndex,colIndex+1);
                pq.push(temp);
                maxi=max(maxi,element);
            }else{
                break;
            }
        }
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};