/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isTransformable = function(s, t) {
    var pos = [], top = []
    for (var i = 0; i < 10; i++)
        pos[i] = [], top[i] = 0
    
    var n = s.length
    for (var i = 0; i < n; i++)
        pos[s[i] - '0'].push(i)
    
    var m = t.length
    for (var i = 0; i < m; i++) {
        var idx = t[i] - '0'
        if (top[idx] >= pos[idx].length) return false
        
        for (var j = 0; j < idx; j++)
            if (top[j] < pos[j].length && pos[j][top[j]] < pos[idx][top[idx]])
                return false
        top[idx]++
    }
    return true
};
