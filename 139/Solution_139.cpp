
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        
        for (int i = 0; i <= s.length(); i++) {  // Fixed: changed "," to ";" in for loop
            if (!dp[i]) continue;
            
            for (string& str : wordDict) {
                if (str.length() + i <= s.length() && s.substr(i, str.length()) == str) {
                    dp[i + str.length()] = true;
                }
            }
        }
        
        return dp[s.length()];
    }
};