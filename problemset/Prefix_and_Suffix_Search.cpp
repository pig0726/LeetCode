struct Node {
  std::vector<int> vals_;
  std::unordered_map<char, Node*> sons;
};

struct Trie {
  Node* root_;
  Trie(): root_(new Node()) {}

  void insert(const std::string& s, int val) {
    root_->vals_.push_back(val);
    Node* ptr = root_;
    for (auto c : s) {
      if (ptr->sons.find(c) == ptr->sons.end()) {
        ptr->sons.insert(std::make_pair(c, new Node()));
      }
      ptr->sons[c]->vals_.push_back(val);
      ptr = ptr->sons[c];
    }
  }

  Node* find(const std::string& s) {
    Node* ptr = root_;
    for (auto c : s) {
      if (ptr->sons.find(c) == ptr->sons.end()) return NULL;
      ptr = ptr->sons[c];
    }
    return ptr;
  }
};

class WordFilter {
public:
    Trie trie;
    Trie _trie;

    WordFilter(vector<string> words) {
        for (int i = 0; i < words.size(); i++)
          trie.insert(words[i], i);
        for (int i = 0; i < words.size(); i++) {
          std::reverse(words[i].begin(), words[i].end());
          _trie.insert(words[i], i);
        }
    }

    int f(string prefix, string suffix) {
      Node* pn = trie.find(prefix);
      std::reverse(suffix.begin(), suffix.end());
      Node* sn = _trie.find(suffix);

      if (!pn || !sn) return -1;

      auto itp = pn->vals_.rbegin();
      auto its = sn->vals_.rbegin();
      while (itp != pn->vals_.rend() && its != sn->vals_.rend()) {
        if (*itp == *its) return *itp;
        else if (*itp < *its) its++;
        else itp++;
      }
      return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
