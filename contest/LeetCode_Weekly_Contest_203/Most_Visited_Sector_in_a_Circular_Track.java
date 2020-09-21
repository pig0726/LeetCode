class Solution {
    public List<Integer> mostVisited(int n, int[] rounds) {
        int start = rounds[0], end = rounds[rounds.length - 1];
        if (start <= end) {
            return generateVectorOfRange(start, end + 1);
        } else {
            ArrayList<Integer> a = generateVectorOfRange(1, end + 1);
            ArrayList<Integer> b = generateVectorOfRange(start, n + 1);
            a.addAll(b);
            return a;
        }
    }
    
    ArrayList<Integer> generateVectorOfRange(int start, int end) {
        ArrayList<Integer> res = new ArrayList();
        for (int i = start; i < end; i++) {
            res.add(i);
        }
        return res;
    }
}

