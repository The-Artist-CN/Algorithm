class Solution:
    def countGoodNumbers(self, n: int) -> int:
        MOD = 1_000_000_007
        return pow(5, (n + 1) // 2, MOD) * pow(4, n // 2, MOD) % MOD


if __name__ == "__main__":
    S = Solution();
    print(S.countGoodNumbers(5));
