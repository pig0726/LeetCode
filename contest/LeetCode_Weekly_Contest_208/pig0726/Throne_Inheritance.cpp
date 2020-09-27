class ThroneInheritance {
public:
    map<string, bool> status;
    map<string, vector<string> > sons;
    map<string, string> fa;
    string KN;

    ThroneInheritance(string kingName) {
        status.clear();
        sons.clear();
        fa.clear();
        KN = kingName;
        status[KN] = true;
        sons[KN] = vector<string>();
    }

    void birth(string parentName, string childName) {
        if (!sons.count(parentName)) {
            sons[parentName] = vector<string>();
        }
        sons[parentName].push_back(childName);
        status[childName] = true;
        fa[childName] = parentName;
    }

    void death(string name) {
        status[name] = false;
    }

    void dfs(const string& name, vector<string>& order) {
        if (status[name])
            order.push_back(name);
        const auto& v = sons[name];
        int m = v.size();
        for (int i = 0; i < m; i++) {
            dfs(v[i], order);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string> order;
        unordered_set<string> data;
        dfs(KN, order);
        return order;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
