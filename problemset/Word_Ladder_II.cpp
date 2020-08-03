class Solution {
public:
    vector<int> edge[10010];
    int vis[10010];
    int d[10010];
    set<int> pre[10010];
    priority_queue<int, vector<pair<int,int> >, greater<pair<int, int> > > pq;

    bool ok(string& s1, string& s2) {
        int cnt = 0;

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) cnt++;
        }

        return cnt == 1;
    }

    void spath(int st, int ed) {
        d[st] = 0;
        pq.push(make_pair(0, st));
        while (!pq.empty()) {
            pair<int, int> e = pq.top();
            pq.pop();

            int dis = e.first;
            int u = e.second;
            if (vis[u]) continue;
            vis[u] = true;

            for (int i = 0; i < edge[u].size(); i++) {
                int v = edge[u][i];
                if (dis + 1 > d[v]) continue;
                if (dis + 1 < d[v]) {
                    pre[v].clear();
                    d[v] = dis + 1;
                    pre[v].insert(u);
                    pq.push(make_pair(d[v], v));
                } else {
                    pre[v].insert(u);
                }
            }
        }
    }

    void dfs(int st, int u, const vector<string>& wl, vector<string>& ans, vector<vector<string> >& ret) {
        ans.push_back(wl[u]);
        if (pre[u].size() == 0) {
            if (u == st) {
                reverse(ans.begin(), ans.end());
                ret.push_back(ans);
                reverse(ans.begin(), ans.end());
            }
            ans.pop_back();
            return;
        }
        set<int>::iterator it;
        for (it = pre[u].begin(); it != pre[u].end(); it++) {
            int v = *it;
            dfs(st, v, wl, ans, ret);
        }
        ans.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > ret;
        int tg = -1;
        for (int i = 0; i < wordList.size(); i++) {
            if (endWord == wordList[i]) {
                tg = i+1;
                break;
            }
        }
        if (tg == -1) return ret;

        for (int i = 0; i < 10010; i++) {
            edge[i].clear();
            pre[i].clear();
            vis[i] = 0;
            d[i] = INT_MAX;
        }

        for (int i = 0; i < wordList.size(); i++) {
            if (ok(beginWord, wordList[i])) {
                edge[0].push_back(i+1);
                edge[i+1].push_back(0);
            }

            for (int j = i + 1; j < wordList.size(); j++) {
                if (ok(wordList[i], wordList[j])) {
                    edge[i+1].push_back(j+1);
                    edge[j+1].push_back(i+1);
                }
            }
        }

        vector<string> ans;
        vector<string> wl;

        wl.push_back(beginWord);
        for (int i = 0; i < wordList.size(); i++) {
            wl.push_back(wordList[i]);
        }

        spath(0, tg);

        dfs(0, tg, wl, ans, ret);

        return ret;
    }
};
