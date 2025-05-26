def isInterleave(s1: str, s2: str, s3: str) -> bool:
    m, n = len(s1), len(s2)
    if m + n != len(s3):
        return False
    
    # dp[i][j] 表示s1前i个字符和s2前j个字符能否组成s3前i+j个字符
    dp = [[False] * (n + 1) for _ in range(m + 1)]
    dp[0][0] = True  # 两个空字符串可以组成空字符串
    
    # 初始化第一列：只使用s1
    for i in range(1, m + 1):
        dp[i][0] = dp[i-1][0] and s1[i-1] == s3[i-1]
    
    # 初始化第一行：只使用s2
    for j in range(1, n + 1):
        dp[0][j] = dp[0][j-1] and s2[j-1] == s3[j-1]
    
    # 填充dp表
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            # 检查s1的当前字符是否匹配s3的当前字符
            from_s1 = dp[i-1][j] and s1[i-1] == s3[i+j-1]
            # 检查s2的当前字符是否匹配s3的当前字符
            from_s2 = dp[i][j-1] and s2[j-1] == s3[i+j-1]
            dp[i][j] = from_s1 or from_s2
    
    return dp[m][n]
