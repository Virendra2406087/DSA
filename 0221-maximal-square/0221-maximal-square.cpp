class Solution {
public:
    vector<int>getNSR(vector<int>& height){
        stack<int>st;
        int n=height.size();
        vector<int>NSR(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                NSR[i]=n;
            }else{
                while(!st.empty() && height[st.top()]>=height[i]){
                    st.pop();
                }
                if(st.empty()){
                    NSR[i]=n;
                }else{
                    NSR[i]=st.top();
                }
            }
            st.push(i);
        }
        return NSR;
    }
    vector<int>getNSL(vector<int>& height){
stack<int>st;
        int n=height.size();
        vector<int>NSL(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                NSL[i]=-1;
            }else{
                while(!st.empty() && height[st.top()]>=height[i]){
                    st.pop();
                }
                if(st.empty()){
                    NSL[i]=-1;
                }else{
                    NSL[i]=st.top();
                }
            }
            st.push(i);
        }
        return NSL;
    }
     int findMax(vector<int>& height){
    //   height
    // width NSR[i]-NSL[i]-1
    vector<int>NSR=getNSR(height);
    vector<int>NSL=getNSL(height);
    int n=height.size();
    vector<int>width(n);
    for(int i=0;i<n;i++){
        width[i]=NSR[i]-NSL[i]-1;
    }
    int maxArea=0;
    for(int i=0;i<n;i++){
        int side=min(width[i],height[i]);
        int a=side*side;
        maxArea=max(maxArea,a);
    }
     return maxArea;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>height(n,0);
        for(int i=0;i<n;i++){
            height[i]=(matrix[0][i]=='1')? 1 :0;
        }
        int maxArea=findMax(height);
        for(int row=1;row<m;row++){
            for(int col=0;col<n;col++){
               if(matrix[row][col]=='0'){
                height[col]=0;
               }else{
                height[col]=height[col]+1;
               }
            }
            maxArea=max(maxArea,findMax(height));

        }
        return maxArea;
    }
};