class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string cleaned;
        // 移除破折号并大写化
        for (char c : s) {
            if (c != '-') {
                cleaned += toupper(c);
            }
        }
        
        if (cleaned.empty()) return "";
        
        int firstGroupSize = cleaned.size() % k;
        if (firstGroupSize == 0) firstGroupSize = k;
        
        string result;
        // 添加第一组
        for (int i = 0; i < firstGroupSize; i++) {
            result += cleaned[i];
        }
        
        // 添加剩余组，每组k个字符
        for (int i = firstGroupSize; i < cleaned.size(); i += k) {
            result += '-';
            for (int j = 0; j < k; j++) {
                result += cleaned[i + j];
            }
        }
        
        return result;
    }
};