class Solution {
public:
    int mySqrt(int x) {
        double last=0, current=x/2.0;
        while(abs(last-current)>0.1)
        {
            last=current;
            current=last-(last*last-x)/(2*last);
        }
        return current;
    }
};
