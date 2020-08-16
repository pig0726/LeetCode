class Solution {
public:
    string simplifyPath(string path) {
        path += '/';
        vector<string> result;
        int preIndex = 0, index = -1;
        while ((index = path.find("/", preIndex+1)) != -1) {
            result.push_back(path.substr(preIndex, index-preIndex));
            preIndex = index;
        }
        
        stack<string> sta;
        for (int i=0; i<result.size(); i++) {
            if (result[i] == "/..") {
                if (!sta.empty())   
                    sta.pop();
            } 
            else if (result[i] == "/." || result[i] == "/")
                ;
            else
                sta.push(result[i]);
        }
        
        string ans;
        while (!sta.empty()) {
            ans = sta.top() + ans;
            sta.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};
