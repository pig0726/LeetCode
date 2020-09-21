/**
 * @param {number[][]} points
 * @return {number}
 */
var minCostConnectPoints = function(points) {
    var n = points.length;
    var p = []
    for (var i = 0; i < n; i++) p[i] = i
    var e = []
    var m = 0
    for (var i = 0; i < n; i++)
        for (var j = i+1; j < n; j++) {
            var dist = Math.abs(points[i][0] - points[j][0]) + Math.abs(points[i][1] - points[j][1])
            e[m] = [i, j, dist]
            m++
        }
    
    e.sort(function (a, b) {return a[2] - b[2]})
    
    var find = function (x) {
        if (x == p[x]) return x
        p[x] = find(p[x])
        return p[x]
    }
    
    var ret = 0
    for (var i = 0; i < m; i++) {
        var pu = find(e[i][0])
        var pv = find(e[i][1]);
        if (pu == pv) continue;
        p[pu] = pv
        ret += e[i][2]
    }
    return ret
};
