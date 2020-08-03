class Solution {
public:
    inline double sq(double x) { 
        return x * x; 
    }
    
    inline const static double eps = 1e-6;
    
    inline const static int dx[8]{
        -1, -1, 0, 1, 1, 1, 0, -1
        };
    
    inline const static int dy[8]{
        0, 1, 1, 1, 0, -1, -1, -1
        };
    
    using point = vector<double>;
    
    double getMinDistSum(vector<vector<int>>& ps) {
        point target(2);
        target[0] = ps[0][0];
        target[1] = ps[0][1];
        double step = 100;
        double mindist = 1e9;
        int n = ps.size();

        while (step > eps) {
            bool flag = false;
            for (int d = 0; d < 8; ++d) {
                point newp = target;
                newp[0] += dx[d] * step;
                newp[1] += dy[d] * step;
                
                double sumdist = 0;
                for (int i = 0; i < n; ++i) {
                    double dist = sqrt(sq(newp[0]-ps[i][0]) + 
                                       sq(newp[1]-ps[i][1]));
                    sumdist += dist;
                }
                if (sumdist < mindist) {
                    flag = true;
                    mindist = sumdist;
                    target = newp;
                }
            }
            if (!flag) step /= 2;
        }
            
        return mindist;
    }
};
