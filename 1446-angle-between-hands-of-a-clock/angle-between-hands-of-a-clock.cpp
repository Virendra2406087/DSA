class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle=0;
        if(hour==12){
            int h=0;
            angle=abs(30*h-5.5*minutes);
        }else{
            angle=abs(30*hour-5.5*minutes);
        }
        if(angle>180){
            return 360-angle;
        }
        return angle;
    }
};