class BrowserHistory {
public:
    int size = 0;
    int cur = 0;
    vector<string> buf;
    BrowserHistory(string homepage) {
        size = 1;
        cur = 0;
        buf.push_back(homepage);
    }
    
    void visit(string url) {
        if (cur+1 == buf.size()) buf.push_back("");
        buf[++cur] = url;
        size = cur+1;
    }
    
    string back(int steps) {
        if (steps > cur) cur = 0;
        else cur -= steps;
        return buf[cur];
    }
    
    string forward(int steps) {
        int delta = size-cur-1;
        delta = min(delta, steps);
        cur += delta;
        return buf[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
