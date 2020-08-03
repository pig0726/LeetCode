import math
class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        def _to_int(x):
            if x.isdigit():
                return int(x)
            elif x.startswith("-") and x[1:].isdigit():
                return -1 * int(x[1:])
            return None

        if (len(tokens) == 1): return int(tokens.pop(0))
        stack = []
        for item in tokens:
            to_int = _to_int(item)
            if to_int is not None:
                stack.append(to_int)
            else:
                n2 = stack.pop(len(stack) - 1)
                n1 = stack.pop(len(stack) - 1)
                if item == "+":
                    stack.append(n1 + n2)
                elif item == "-":
                    stack.append(n1 - n2)
                elif item == "*":
                    stack.append(n1 * n2)
                elif item == "/":
                    if n1 * n2 >= 0:
                        stack.append(n1 / n2)
                    else:
                        stack.append(int(math.ceil(1.0 * n1 / n2)))
        return stack.pop(len(stack) - 1)


