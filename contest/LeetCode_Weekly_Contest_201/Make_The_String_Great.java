class Solution {
    public String makeGood(String s) {
        char[] ret = new char[s.length()+10];
        int idx = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (idx == 0) {
                ret[idx++] = s.charAt(i);
                continue;
            }
            char a = ret[idx-1];
            char b = s.charAt(i);

            if (('a' <= a && a <= 'z' && 'A' <= b && b <= 'Z' && a-'a' == b-'A') ||
                ('A' <= a && a <= 'Z' && 'a' <= b && b <= 'z' && a-'A' == b-'a'))
                idx--;
            else ret[idx++] = b;

        }
        return String.copyValueOf(ret, 0, idx);
    }
}

