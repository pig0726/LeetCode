class Solution {
    public char findKthBit(int n, int k) {
        ArrayList<Integer> ret = new ArrayList<Integer>();
        ret.add(0);
        n--;
        k--;

        for (int i = 0; i < n; ++i) {
            ArrayList<Integer> b = new ArrayList<Integer>();
            for (int j = ret.size()-1; j >= 0; --j) {
                b.add(1 - ret.get(j));
            }
            ret.add(1);
            ret.addAll(b);
        }

        return ret.get(k) == 1 ? '1' : '0';
    }
}
