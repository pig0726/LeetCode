class Solution {
public:
    std::set<std::string> folders;
    std::map<std::string, int> fcnt;
    
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ret;
        
        for (const auto& f : names) {
            auto it = fcnt.find(f);
            if (it == fcnt.end()) {
                ret.push_back(f);
                fcnt[f] = 0;
            } else {
                int cnt = it->second;
                for (int i = cnt+1; ; ++i) {
                    string newf = f + "(" + std::to_string(i) + ")";
                    auto it2 = fcnt.find(newf);
                    if (it2 == fcnt.end()) {
                        it->second = i;
                        fcnt[newf] = 0;
                        ret.push_back(newf);
                        break;
                    }
                }
            }
        }
        return ret;
    }
};
