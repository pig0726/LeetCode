class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (string log : logs) {
            if (log == "./") continue;
            else if (log == "../") depth = depth > 0 ? depth - 1 : depth;
            else depth++;
        }
        return depth;
    }
};

