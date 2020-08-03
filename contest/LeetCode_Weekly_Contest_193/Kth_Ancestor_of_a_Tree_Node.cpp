const int S = 20;
const int N = 50005;

class TreeAncestor {
public:
    int an[N][S];
    int n;
    
    TreeAncestor(int n, vector<int>& parent) {
        this->n = n;
     
        memset(an, -1, sizeof an);
        for (int i = 1; i < n; ++i) 
            an[i][0] = parent[i];
        
        for (int b = 1; b < S; ++b) {
            for (int i = 1; i < n; ++i) {
                int p = an[i][b-1];
                if (p == -1) an[i][b] = -1;
                else an[i][b] = an[p][b-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if (node == 0) return -1;
        for (int b = 0; node != -1 && k && b < S; ++b) if (k & (1<<b)) {
            node = an[node][b];
            k -= 1<<b;
        }
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
