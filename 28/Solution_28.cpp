#include <string>
#include <iostream>
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
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        if(m == 0) return 0;
        //设置哨兵
        s.insert(s.begin(),' ');
        p.insert(p.begin(),' ');
        vector<int> next(m + 1);
        //预处理next数组
        for(int i = 2, j = 0; i <= m; i++){
            while(j and p[i] != p[j + 1]) j = next[j];
            if(p[i] == p[j + 1]) j++;
            next[i] = j;
        }
        //匹配过程
        for(int i = 1, j = 0; i <= n; i++){
            while(j and s[i] != p[j + 1]) j = next[j];
            if(s[i] == p[j + 1]) j++;
            if(j == m) return i - m;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    string source = "hello world";
    
    // 测试用例 1
    string target = "world";
    int index = sol.find_str_in_String(source, target);
    cout << "Index of first occurrence: " << index << endl;  // 输出: 6
    
    // 测试用例 2
    target = "hello";
    index = sol.find_str_in_String(source, target);
    cout << "Index of first occurrence: " << index << endl;  // 输出: 0
    
    // 测试用例 3
    target = "test";
    index = sol.find_str_in_String(source, target);
    cout << "Index of first occurrence: " << index << endl;  // 输出: -1
    
    // 测试用例 4
    target = "";
    index = sol.find_str_in_String(source, target);
    cout << "Index of first occurrence: " << index << endl;  // 输出: 0
    
    return 0;
}
