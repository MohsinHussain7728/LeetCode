class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //Nearest point 
        int xi = clamp(xCenter,x1,x2);
        int yi = clamp(yCenter,y1,y2);

        // if(xCenter < x1) xi = x1;
        // else if(x2 < xCenter) xi = x2;
        // else xi = xCenter;

        // if(yCenter < y1) yi = y1;
        // else if(y2 < yCenter) yi = y2;
        // else yi = yCenter;

        return ((xi - xCenter)*(xi-xCenter) + (yi-yCenter)*(yi-yCenter) <= (radius*radius));

        
    }
};