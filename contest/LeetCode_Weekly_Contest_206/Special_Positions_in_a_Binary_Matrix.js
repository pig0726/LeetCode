/**
 * @param {number[][]} mat
 * @return {number}
 */
var numSpecial = function(mat) {
    var n = mat.length;
    var m = mat[0].length;
    var ret = 0;
    for (var i = 0; i < n; i++)
        for (var j = 0; j < m; j++) if (mat[i][j]) {
            var flag = true;
            for (var r = 0; r < n; r++) if (r != i && mat[r][j]) {
                flag = false;
                break;
            }
            if (!flag) continue;
            for (var c = 0; c < m; c++) if (c != j && mat[i][c]) {
                flag = false;
                break;
            }
            if (flag) ret++; 
        }
    return ret;
};
