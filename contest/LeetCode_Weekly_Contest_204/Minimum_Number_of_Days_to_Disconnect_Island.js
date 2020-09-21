/**
 * @param {number[][]} grid
 * @return {number}
 */

const dr = [0, -1, 0, 1];
const dc = [-1, 0, 1, 0];

var vis = null
var cnt = null

function makeArr(n, m) {
    var a = new Array()
    for (var i = 0; i < n; ++i) {
        a[i] = new Array()
        for (var j = 0; j < m; ++j)
            a[i][j] = 0
    }
    return a
}

function dfs(grid, r, c) {
    vis[r][c] = true;
    cnt++;
    for (var k = 0; k < 4; ++k) {
        var x = r + dr[k];
        var y = c + dc[k];
        if (0 <= x && x < n && 0 <= y && y < m && grid[x][y] && !vis[x][y])
            dfs(grid, x, y);
    }
}

function check(grid, tot) {
    for (var i = 0; i < n; ++i)
        for (var j = 0; j < m; ++j) if (grid[i][j]) {
            cnt = 0;
            dfs(grid, i, j);
            if (cnt !== tot) return true;
            else return false;
        }
    return false;
}

var minDays = function(grid) {
    n = grid.length;
    m = grid[0].length;
        
    onecnt = 0;
    for (var i = 0; i < n; ++i)
        for (var j = 0; j < m; ++j)
            if (grid[i][j]) onecnt++;
        
    if (onecnt == 1) return 1;
        
    vis = makeArr(n, m)
    if (check(grid, onecnt)) return 0;
        
    for (var i = 0; i < n; ++i)
        for (var j = 0; j < m; ++j) if (grid[i][j]) {
            vis = makeArr(n, m)
            grid[i][j] = 0;
            if (check(grid, onecnt-1)) return 1;
            grid[i][j] = 1;
        }
        
    return 2;
};