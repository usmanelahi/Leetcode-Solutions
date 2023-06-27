class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        def rec(s):
            stack = []
            idx = 0
            L = len(s)
            while idx < L:
                if s[idx] == '(':
                    val, length = rec(s[idx + 1:])
                    idx += length + 1
                    stack.append(val)
                elif s[idx] == ')':
                    val = 2 * sum(stack) if stack else 1
                    return val, idx
                idx += 1
            
            val = sum(stack) if stack else 1
            return val, idx
            
        return rec(s)[0]
