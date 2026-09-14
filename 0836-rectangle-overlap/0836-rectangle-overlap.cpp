class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // int x1 = rec1[0];
        // int y1 = rec1[1];
        // int x2 = rec1[2];
        // int y2 = rec1[3];

        // int p1 = rec2[0];
        // int q1 = rec2[1];
        // int p2 = rec2[2];    Just like merge intervals problem just check for x axis and y axis
        // int q2 = rec2[3];    separately.


        return (rec1[0]<rec2[2] && rec2[0]<rec1[2] && rec1[1]<rec2[3] && rec2[1]<rec1[3]);
    }
};