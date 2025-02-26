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
