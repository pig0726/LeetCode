class Solution {
    ArrayList<Integer>[] pos;
    int n;
    public boolean isTransformable(String s, String t) {
        n = s.length();

        pos = new ArrayList[10];
        for (int i = 0; i < 10; ++i)
            pos[i] = new ArrayList<Integer>();

        for (int i = 0; i < n; ++i) {
            int idx = s.charAt(i) - '0';
            pos[idx].add(i);
        }

        int[] p = new int[10];
        for (int i = 0; i < 10; ++i) p[i] = 0;

        for (int i = 0; i < t.length(); ++i) {
            int idx = t.charAt(i) - '0';
            if (p[idx] >= pos[idx].size()) return false;

            int where = pos[idx].get(p[idx]);
            p[idx]++;

            for (int v = 0; v < idx; ++v) {
                if (p[v] >= pos[v].size()) continue;
                if (pos[v].get(p[v]) < where) return false;
            }
        }

        return true;
    }
}
