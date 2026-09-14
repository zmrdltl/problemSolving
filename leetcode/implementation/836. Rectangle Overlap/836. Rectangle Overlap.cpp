struct Point {
    int x,y;
};

struct Rect{
    Point LeftBottom, RightTop;
};

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        Rect r1 = {rec1[0], rec1[1], rec1[2], rec1[3]};
        Rect r2 = {rec2[0], rec2[1], rec2[2], rec2[3]};
        if(r1.LeftBottom.x >= r2.RightTop.x) return false;
        if(r1.LeftBottom.y >= r2.RightTop.y) return false;
        if(r1.RightTop.x <= r2.LeftBottom.x) return false;
        if(r1.RightTop.y <= r2.LeftBottom.y) return false;
        return true;
    }
};