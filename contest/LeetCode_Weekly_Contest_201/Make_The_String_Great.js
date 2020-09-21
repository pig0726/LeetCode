/**
 * @param {string} s
 * @return {string}
 */
var makeGood = function(s) {
    var ret = [];
    var n = s.length;
    
    for (var i = 0; i < n; ++i) {
        if (ret.length && 
            ('a' <= ret[ret.length-1] && ret[ret.length-1] <= 'z' && 
             'A' <= s[i] && s[i] <= 'Z' && 
             ret[ret.length-1].toLowerCase() === s[i].toLowerCase()) ||
            ('A' <= ret[ret.length-1] && ret[ret.length-1] <= 'Z' && 
             'a' <= s[i] && s[i] <= 'z' && 
             ret[ret.length-1].toLowerCase() === s[i].toLowerCase())) 
            ret.pop();
        else ret.push(s[i]);
    }
    
    return ret.join('');
};
