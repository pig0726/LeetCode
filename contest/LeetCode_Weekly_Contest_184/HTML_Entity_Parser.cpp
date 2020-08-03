const int N = 1e5+5;
char buf[N];
int idx; 

class Solution {
public:
  
    string Find(const std::string& s) {
      if (s == "&quot;") return "\"";
      else if (s == "&apos;") return "'";
      else if (s == "&amp;") return "&";
      else if (s == "&gt;") return ">";
      else if (s == "&lt;") return "<";
      else if (s == "&frasl;") return "/";
      return "";
    }
  
    string entityParser(string text) {
      idx = 0;
      int n = text.length();
      for (int i = 0; i < n; ) {
        if (text[i] != '&') {
          buf[idx++] = text[i++];
        } else {
          int found = -1;
          for (int len = 4; len <= 7 && i + len <= n; ++len) {
            string ans = Find(text.substr(i, len));
            if (ans.empty()) continue;
            buf[idx++] = ans.front();
            found = len;
            break;
          }
          if (found == -1) {
            buf[idx++] = '&';
            found = 1;
          }
          i += found;
        }
      }
      buf[idx] = 0;
      return string(buf);
    }
};
