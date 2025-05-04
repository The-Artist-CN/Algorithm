class Solution_70:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        p, q = 1, 2
        for _ in range(n - 2):
            r = p + q
            p, q = q, r
        return q  # or return r (both work)
