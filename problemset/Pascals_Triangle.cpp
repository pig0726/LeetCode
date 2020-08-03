class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ret;
        vector<int> v1, v2;
        vector<int>* p1 = &v1;
        vector<int>* p2 = &v2;
        for (int level = 1; level <= numRows; level++) {
            p1->clear();
            if (level == 1) {
                p1->push_back(1);
            } else {
                p1->push_back(1);
                for (int i = 0; i < p2->size()-1; i++) {
                    p1->push_back((*p2)[i] + (*p2)[i+1]);
                }
                p1->push_back(1);
            }

            ret.push_back(*p1);
            swap(p1, p2);
        }
        return ret;
    }
};
