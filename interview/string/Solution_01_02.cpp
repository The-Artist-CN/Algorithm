#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool canPermute(string s1, string s2) {
    // 如果长度不同，直接返回 false
    if (s1.length() != s2.length()) {
        return false;
    }

    // 对 s1 和 s2 进行排序（原地排序）
    sort(s1.begin(), s1.end());  // 正确调用 sort
    sort(s2.begin(), s2.end());  // 正确调用 sort

    // 比较排序后的字符串
    return s1 == s2;
}

bool canPermuteV2(string s1 ,string s2){
    int checker = 0;
    for (char c : s1) {
        checker ^= (1 << (c - 'a'));
    }
    for (char c : s2) {
        checker ^= (1 << (c - 'a'));
    }

    // 如果 checker 为 0，说明字符频率相同
    return checker == 0;
}


int main() {
    string s1 = "abcd";
    string s2 = "badc";

    cout << "Can permute: " << canPermute(s1, s2) << endl;  // 输出 1 (true)
    cout << "s1 after sorting: " << s1 << endl;  // 输出排序后的 s1
    cout << "s2 after sorting: " << s2 << endl;  // 输出排序后的 s2

    return 0;
}
