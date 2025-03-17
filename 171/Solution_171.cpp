#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int titleToNumber(string title) {
    int result = 0;
    for (char ch : title) {  // 修正：遍历字符串中的每个字符
        int value = ch - 'A' + 1;
        result = result * 26 + value;
    }
    return result;
}

int main() {
    // 测试用例 1: "A"
    assert(titleToNumber("A") == 1);

    // 测试用例 2: "AB"
    assert(titleToNumber("AB") == 28);

    // 测试用例 3: "ZY"
    assert(titleToNumber("ZY") == 701);

    cout << "所有测试用例通过！" << endl;
    return 0;
}
