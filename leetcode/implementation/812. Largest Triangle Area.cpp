struct Point {
    int x,y;
};
class Solution {
public:

    double getTriangleArea(Point a, Point b, Point c){
        return abs((a.x*b.y + b.x*c.y + c.x*a.y) - (b.x*a.y + c.x*b.y + a.x*c.y)) / 2.0;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;
        int sz = points.size();
        for(int i = 0; i < sz; i++) {
            for(int j = i + 1; j < sz; j++) {
                for(int k = j + 1; k < sz; k++) {
                    Point a = {points[i][0], points[i][1]};
                    Point b = {points[j][0], points[j][1]};
                    Point c = {points[k][0], points[k][1]};

                    maxArea = max(maxArea, getTriangleArea(a, b, c));
                }
            }
        }
        return maxArea;
    }
};