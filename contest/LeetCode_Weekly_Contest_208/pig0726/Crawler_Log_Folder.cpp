class Solution {
public:
    int minOperations(vector<string>& logs) {
        int size = 0;

        for (const auto& s : logs) {
            if (s == "./") {
                continue;
            } else if (s == "../") {
                if (size) --size;
            } else {
                size++;
            }
        }

        return size;
    }
};
