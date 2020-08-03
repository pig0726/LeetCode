/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct Elem {
        int id;
        int lid, rid;
        vector<int> dis;
    };
    int gid;
    int ret;
    vector<Elem> es;
    
    void dfs(TreeNode* root, const int dist) {
        int id = ++gid;
        Elem& e = es[id];
        e.id = gid;
        e.lid = e.rid = -1;
        
        if (root->left) {
            e.lid = gid + 1;
            dfs(root->left, dist);
            for (int a : es[e.lid].dis) 
                e.dis.push_back(a + 1);
        }
        if (root->right) {
            
            e.rid = gid + 1;
            dfs(root->right, dist);
            for (int a : es[e.rid].dis) 
                e.dis.push_back(a + 1);
        }
        
        if (es[id].lid == -1 && es[id].rid == -1) {
            e.dis.push_back(0);
            return;
        }
        
        
        if (e.lid != -1 && e.rid != -1) {
            
            int n = es[e.lid].dis.size();
            int m = es[e.rid].dis.size();
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) {
                    int d = es[e.lid].dis[i] + es[e.rid].dis[j] + 2;
                    if (d <= dist) ++ret;
                }
        }
    }
    
    int countPairs(TreeNode* root, int dist) {
        gid = -1;
        ret = 0;
        es.resize(1024 + 5);
        dfs(root, dist);
        return ret;
    }
};
