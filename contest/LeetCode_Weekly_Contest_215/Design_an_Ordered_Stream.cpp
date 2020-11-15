class OrderedStream {
public:      
    int n; // 数组长度
    vector<string> data; // 数组
    vector<bool> vis; // 标记数组，标记下标是否有元素
    int ptr; // 指针
    
    OrderedStream(int n) {
        this->n = n;
        data.resize(n);
        vis.assign(n, false);
        ptr = 0;
    }
    
    vector<string> insert(int id, string value) {
        id--;
        data[id] = value;
        vis[id] = true;
        
        vector<string> ret;
        while (ptr < n && vis[ptr]) {
            ret.push_back(data[ptr]);
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
