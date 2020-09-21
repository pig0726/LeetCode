class Solution:
    def simplifyPath(self, path: str) -> str:
        res = list()
        
        # split input
        directories = [d for d in path.split('/') if d]
        
        # process directories
        for d in directories:
            if d == '.':
                pass
            elif d == '..':
                if res:
                    res.pop()
            else:
                res.append(d)
                
        # combine to canonical path
        return '/' + '/'.join(res)

