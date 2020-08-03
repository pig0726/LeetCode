class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat.front().size();
        
        using piv = pair<int, vector<int>>;
        set<piv> data;
        
        vector<int> cursor(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) 
            cursor[i] = 0, sum += mat[i][0];
        data.insert(make_pair(sum, cursor));
  
        for (int i = 0; i < k; ++i) {
            sum = data.begin()->first;
            cursor = data.begin()->second;
            data.erase(data.begin());
            
            for (int j = 0; j < n; ++j) if (cursor[j]+1 < m) {
                vector<int> tmp = cursor;
                int newsum = sum;
                tmp[j]++;
                newsum += mat[j][tmp[j]] - mat[j][tmp[j]-1];
                data.insert(make_pair(newsum, tmp));
            }
        }
        return sum;
        
    }
};
