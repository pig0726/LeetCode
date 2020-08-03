/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        map<int, UndirectedGraphNode*> m;
        queue<UndirectedGraphNode*> q;
        m.insert(make_pair(node->label, new UndirectedGraphNode(node->label)));
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode* u = q.front();
            q.pop();
            UndirectedGraphNode* uu = m[u->label];
            for (int i = 0; i < u->neighbors.size(); i++) {
                UndirectedGraphNode* v = u->neighbors[i];
                if (m.find(v->label) == m.end()) {
                    m.insert(make_pair(v->label, new UndirectedGraphNode(v->label)));
                    q.push(v);
                }
                uu->neighbors.push_back(m[v->label]);
            }
        }
        return m[node->label];
    }
};
