class Solution {
public:
  string longestDiverseString(int a, int b, int c) {
    using pii = pair<int, int>;
    vector<pii> re{{a, 0}, {b, 1}, {c, 2}};

    using pci = pair<char, int>;
    vector<pci> data;

    while (true) {
      sort(re.begin(), re.end(),
           [](const pii& a, const pii& b) {
              return a.first > b.first;});

      int id = -1;
      for (int i = 0; i < 3; ++i) {
        if (!re[i].first) continue;
        char c = re[i].second + 'a';
        if (data.empty() || data.back().first != c) {
          id = i;
          break;
        }
      }
      if (id == -1) break;
      data.push_back(
        make_pair(re[id].second+'a', 1));
      re[id].first--;
    }

    sort(re.begin(), re.end(),
         [](const pii& a, const pii& b) {
            return a.second < b.second;});

    for (int i = 0; i < data.size(); ++i)
      if (re[data[i].first - 'a'].first) {
        re[data[i].first - 'a'].first--;
        data[i].second++;
      }

    string ret;
    for (const auto& p : data) {
      ret += string(p.second, p.first);
    }

    return ret;
  }
};
