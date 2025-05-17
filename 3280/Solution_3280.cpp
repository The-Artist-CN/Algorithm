#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string binary(int x) {
        string s;
        while (x) {
            s.push_back('0' + (x & 1)); // 将二进制的最低位添加到字符串
            x >>= 1; // 右移一位
        }
        reverse(s.begin(), s.end()); // 反转字符串以获得正确的二进制顺序
        return s.empty() ? "0" : s;  // 如果x为0，返回"0"
    }

    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));  // 提取年份
        int month = stoi(date.substr(5, 2)); // 提取月份
        int day = stoi(date.substr(8, 2));   // 提取日期
        return binary(year) + "-" + binary(month) + "-" + binary(day); // 拼接结果
    }
};

int main() {
    Solution solution;
    string date = "2025-01-02";
    cout << solution.convertDateToBinary(date) << endl; // 输出二进制日期
    return 0;
}

