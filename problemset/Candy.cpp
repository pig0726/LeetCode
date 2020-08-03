class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int>* edge = new vector<int>[size+1];
        int* indegree = new int[size+1];
        memset(indegree, 0, sizeof(int)*size);
        for (int i = 0; i < size - 1; i++) {
            if (ratings[i] > ratings[i+1]) {
                edge[i+1].push_back(i);
                ++indegree[i];
            } else if (ratings[i] < ratings[i+1]) {
                edge[i].push_back(i+1);
                ++indegree[i+1];
            }
        }
        vector<int> v1;
        vector<int> v2;
        vector<int>* p1;
        vector<int>* p2;
        p1 = &v1;
        p2 = &v2;
        int c = 1;
        int ret = 0;
        for (int i = 0; i < size; i++) {
            if (!indegree[i]) p1->push_back(i);
        }
        while (!p1->empty()) {
            p2->clear();
            for (int i = 0; i < p1->size(); i++) {
                int u = (*p1)[i];
                ret += c;
                for (int k = 0; k < edge[u].size(); k++) {
                    int v = edge[u][k];
                    --indegree[v];
                    if (!indegree[v]) p2->push_back(v);
                }
            }
            ++c;
            swap(p1, p2);
        }
        delete[] edge;
        delete[] indegree;
        return ret;
    }
};
