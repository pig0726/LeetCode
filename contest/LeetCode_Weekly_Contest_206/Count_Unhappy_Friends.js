/**
 * @param {number} n
 * @param {number[][]} preferences
 * @param {number[][]} pairs
 * @return {number}
 */
var unhappyFriends = function(n, ps, pairs) {
    var data = []
    var vis = []
    for (var i = 0; i < n; i++) {
        data[i] = {}
        vis[i] = true
        var len = ps[i].length
        for (var j = 0; j < len; j++) {
            data[i][ps[i][j]] = j
        }
    }
    
    var work = function(x, y, u, v) {
        var pu = data[x][u]
        var py = data[x][y]
        var px = data[u][x]
        var pv = data[u][v]
        if (pu < py && px < pv) return true
        return false
    }
    
    var m = pairs.length;
    for (var i = 0; i < m; i++) {
        for (var j = 0; j < m; j++) if (i != j) {
            var x = pairs[i][0], y = pairs[i][1], u = pairs[j][0], v = pairs[j][1];
            
            if (work(x,y,u,v) || work(x,y,v,u)) vis[x] = false
            if (work(y,x,u,v) || work(y,x,v,u)) vis[y] = false
        }
    }
    
    var ret = 0;
    for (var i = 0; i < n; i++) if (!vis[i]) ret++;
    return ret;
};
