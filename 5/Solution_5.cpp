

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 1;
        int start = 0;
        
        // 所有长度为1的子串都是回文
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        
        // 检查长度为2的子串
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }
        
        // 检查长度大于2的子串
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};
