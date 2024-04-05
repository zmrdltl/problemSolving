struct Coord {
    int x, y;
    bool operator<(const Coord& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

class Solution {
public:
    bool isPathCrossing(string path) {
        Coord coord = {0,0};
        map <Coord, bool> visitMap;
        visitMap[coord] = true;
        for(auto p : path) {
            if (p == 'N') {
                coord.y++;
            } else if (p == 'E') {
                coord.x++;
            } else if (p == 'S') {
                coord.y--;
            } else {
                coord.x--;
            }
            if (visitMap.count(coord)) return true;
            visitMap[coord] = true;
        }
        return false;
    }
};