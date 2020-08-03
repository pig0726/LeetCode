class Solution {
public:
    int toInt(const string& s) {
        int sum = 0;
        for (char c : s) sum = sum * 10 + c-'0';
        return sum;
    }
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> fitems;
        map<int, map<string, int> > data;
        for (const auto& e : orders) {
            fitems.insert(e[2]);
            data[toInt(e[1])][e[2]] += 1;
        }
        
        vector<vector<string> > ret;
        
        vector<string> header;
        header.push_back("Table");
        for(const auto& s : fitems) header.push_back(s);
        ret.push_back(header);
        
        for (const auto& p : data) {
            vector<string> line;
            const auto& tid = p.first;
            const auto& cnt = p.second;
            line.push_back(to_string(tid));
            for (const auto& f : fitems) {
                auto it = cnt.find(f);
                if (it == cnt.end()) line.push_back("0");
                else line.push_back(to_string(it->second));
            }
            ret.push_back(line);
        }
        return ret;
    }
};
