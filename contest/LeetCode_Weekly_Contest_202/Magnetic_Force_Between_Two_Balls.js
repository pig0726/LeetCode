/**
 * @param {number[]} position
 * @param {number} m
 * @return {number}
 */
var maxDistance = function(p, m) {
    p.sort(function(a, b) {return a-b;});
    
    var check = function(dist) {
        var cnt = 1, pre = p[0], n = p.length;
        for (var i = 1; i < n && cnt < m; ++i) {
            if (p[i] - pre >= dist) {
                pre = p[i];
                cnt++;
            }
        }
        return cnt == m;
    };
    
    var low = 0, hight = 1000000000, ans = 0;
    while (low <= hight) {
        var mid = (low + hight) >> 1;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            hight = mid - 1;
        }
    }
    return ans;
};
