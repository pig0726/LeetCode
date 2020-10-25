const int INF = 0x3f3f3f3f;
const int N = 505;
class Solution {
public:
    int n, m;
    using pii = pair<int, int>;
    vector<pii> data;
    vector<int> rusev, cusev;
    vector<unordered_map<int, vector<int>>> rnum, cnum;
    vector<int> grp;
    unordered_map<int, vector<int>> grpmap;
    
    void dfs(int id, int val, int r, int c) {
        grp[r * m + c] = id;
        grpmap[id].push_back(r * m + c);
        
        for (int cc : rnum[r][val]) {
            if (grp[r * m + cc] != -1) continue;
            dfs(id, val, r, cc);
        }
        
        for (int rr : cnum[c][val]) {
            if (grp[rr * m + c] != -1) continue;
            dfs(id, val, rr, c);
        }
    }
    
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& mx) {
        n = mx.size();
        m = mx.front().size();
        
        grp.resize(n * m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                grp[i * m + j] = -1;       
        
        rnum.resize(n);
        cnum.resize(m);
        vector<vector<int>> ret = mx;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                ret[i][j] = -1;
                int pos = i * m + j;
                data.push_back(make_pair(mx[i][j], i * m + j));
                
                if (!rnum[i].count(mx[i][j])) {
                    rnum[i][mx[i][j]] = vector<int>();
                }
                rnum[i][mx[i][j]].push_back(j);
                
                if (!cnum[j].count(mx[i][j])) {
                    cnum[j][mx[i][j]] = vector<int>();
                }
                cnum[j][mx[i][j]].push_back(i);
            }
        
        sort(data.begin(), data.end());
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grp[i * m + j] == -1) {
                    grpmap[i * m + j] = vector<int>();
                    dfs(i * m + j, mx[i][j], i, j);
                }
        
        rusev.assign(n, 0);
        cusev.assign(m, 0);
        
        for (int i = 0; i < data.size(); i++) {
            int row = data[i].second / m;
            int col = data[i].second % m;
            
            if (ret[row][col] != -1) continue;
            
            int id = grp[data[i].second];
            int val = 0;
            for (int pos : grpmap[id]) {
                int r = pos / m;
                int c = pos % m;
                val = max(val, rusev[r]+1);
                val = max(val, cusev[c]+1);
            }
            
            for (int pos : grpmap[id]) {
                int r = pos / m;
                int c = pos % m;
                ret[r][c] = val;
                rusev[r] = val;
                cusev[c] = val;
            }
                 
        }
        
        return ret;
    }
};
