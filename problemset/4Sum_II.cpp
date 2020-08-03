class Solution {
public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    if (A.empty() || B.empty() || C.empty() || D.empty()) return 0;
    int ret = 0;
    unordered_map<long long, int> data;
    for (int i1 = 0; i1 < A.size(); i1++) {
      for (int i2 = 0; i2 < B.size(); i2++) {
        long long sum = A[i1] + B[i2];
        auto it = data.find(sum);
        if (it == data.end()) {
          data.insert(make_pair(sum, 1));
        } else {
          ++it->second;
        }
      }
    }

    for (int i3 = 0; i3 < C.size(); i3++) {
      for (int i4 = 0; i4 < D.size(); i4++) {
        long long sum = C[i3] + D[i4];
        long long delta = 0 - sum;
        auto it = data.find(delta);
        if (it == data.end()) continue;
        ret += it->second;
      }
    }

    return ret;
  }
};
