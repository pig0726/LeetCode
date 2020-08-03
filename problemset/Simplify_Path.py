class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        parts = path.strip().strip("/").split("/")
        stack = []
        for p in parts:
            if p == "." or not p: continue
            elif p == "..": stack.pop(len(stack)-1) if stack else None
            else: stack.append(p)
        return "/"+"/".join(stack)
