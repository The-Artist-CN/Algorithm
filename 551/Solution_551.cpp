#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkRecord(string str) {
        int A_count = 0; // 记录 'A' 的数量
        int L_streak = 0; // 记录连续 'L' 的数量

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == 'A') {
                A_count++;
                if (A_count >= 2) {
                    return false; // 超过一个 'A'
                }
                L_streak = 0; // 重置连续 'L' 计数
            } else if (str[i] == 'L') {
                L_streak++;
                if (L_streak >= 3) {
                    return false; // 连续三个或更多 'L'
                }
            } else {
                L_streak = 0; // 遇到 'P' 时重置连续 'L' 计数
            }
        }

        return true; // 通过所有检查
    }
};

int main() {
    Solution solution;
    string s1 = "PPALLP";
    string s2 = "PPALLL";

    cout << solution.checkRecord(s1) << endl; // 输出: 1 (true)
    cout << solution.checkRecord(s2) << endl; // 输出: 0 (false)

    return 0;
}
