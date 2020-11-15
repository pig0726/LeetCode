class OrderedStream {
public:
    int n;
    int ptr = 0;
    vector<string> data;
    vector<bool> vis;
    
    OrderedStream(int n) {
        this->n = n;
        data.resize(n);
        vis.assign(n, false);
    }
    
    vector<string> insert(int id, string value) {
        id--;
        data[id] = value;
        vis[id] = true;
        
        vector<string> ret;
        for (int i = ptr; i < n && vis[i]; i++) {
            ret.push_back(data[i]);
            ptr++;
        }
        
        return ret;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
