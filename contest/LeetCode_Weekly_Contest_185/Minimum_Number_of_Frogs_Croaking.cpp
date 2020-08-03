class Solution {
public:
    char findnextch(char c) {
        static const char buf[6] = "croak";
        for (int i = 0; i < 4; ++i) 
            if (buf[i] == c) return buf[i+1];
        return 'c';
    }
    
    int minNumberOfFrogs(string cof) {
        int total = -1;
        map<char, set<int> > data;
        
        for (char ch : cof) {
            char nextch = findnextch(ch);
            auto it = data.find(ch);
            
            if (it == data.end() || it->second.empty()) {
                if (ch != 'c') return -1;
                ++total;
                data[nextch].insert(total);
                continue;
            }
            auto front = it->second.begin();
            data[nextch].insert(*front);
            it->second.erase(front);
        }
        for (const auto& e : data) 
            if (e.first != 'c' && !e.second.empty()) 
                return -1;
        return total+1;
    }
};
