class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int move=0;
        while(target>1){
            if(maxDoubles==0){
                int steps=target-1;
                int target=1;
                move=move+steps;
                break;
            }else{
                if(target & 1){
                    target--;
                    move++;
                }else{
                    target=target>>1;
                    maxDoubles--;
                    move++;
                }
            }
        }
        return move;
    }
};