/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 1) return points.size();
        int ret = 0;
        for (int i = 0; i < points.size(); i++) {
            typedef map<pair<int, int>, int> Data;
            Data data;
            int same = 0;
            for (int j = 0; j < points.size(); j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    same++;
                } else {
                    int dx = points[i].x - points[j].x;
                    int dy = points[i].y - points[j].y;
                    int d = __gcd(dx, dy);
                    int x = dx/d;
                    int y = dy/d;
                    data[make_pair(x, y)]++;
                }
            }
            int cnt = 0;
            for (Data::iterator it = data.begin(); it != data.end(); it++) {
                cnt = max(cnt, it->second);
            }
            ret = max(ret, cnt + same);
        }
        return ret;
    }
};
