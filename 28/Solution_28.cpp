#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find_str_in_String(string source, string target) {
        if (target.empty()) return 0;  // 空串处理
        if (source.length() < target.length()) return -1;
        
        for (int i = 0; i <= source.length() - target.length(); ++i) {
            bool found = true;
            for (int j = 0; j < target.length(); ++j) {
                if (source[i + j] != target[j]) {
                    found = false;
                    break;
                }
            }
            if (found) return i;
        }
        return -1;
    }

    vector<int> computeLSP(const string& pattern){
        int n = pattern.length();
        vector<int> lsp(n,0);
        int len = 0;
        int i = 1;

        while (i < n){
            if (pattern[i] == pattern[len]){
                len++;
                lsp[i] = len;
                i++;
            } else {
                if (len != 0){
                    len = lsp[len - 1];
                } else {
                    lsp[i] = 0;
                    i++;
                }
            }
        }

        return lsp;
    }

    int find_str_in_String_use_kmp(const string& source , const string& target){
        if (source.empty()) return -1;
        if (target.empty()) return 0;

        int m = source.length();
        int n = target.length();

        vector<int> lsp = computeLSP(target);

        int i = 0;
        int j = 0;

        while (i < m){
            if (source[i] == target[j]){
                i++;
                j++;

                if (j == n){
                    return i - j;
                }
            } else {
                if (j != 0 ){
                    j = lsp[j-1];
                } else {
                    i++;
                }
            }
        }

        return  -1 ;
    }
};
int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    Solution sol;
    int pos = sol.find_str_in_String_use_kmp(text, pattern);
    
    if (pos != -1) {
        cout << "模式串在主串的位置: " << pos << endl;  // 输出 10
    } else {
        cout << "未找到模式串" << endl;
    }
    return 0;
}
