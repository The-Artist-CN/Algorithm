#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    int n = s.length();
    int end = n - 1;

    // 跳过末尾的空格
    while (end >= 0 && s[end] == ' ') {
        end--;
    }
    cout << end << endl;

    // 如果整个字符串都是空格，返回 0
    if (end < 0) {
        return 0;
    }

    int start = end;

    // 找到最后一个单词的开始位置
    while (start >= 0 && s[start] != ' ') {
        start--;
    }

    cout << start << endl;

    // 计算单词的长度
    return end - start;
}

int main() {
    string s = "Hello World";
    cout << "Length of last word: " << lengthOfLastWord(s) << endl;
    return 0;
}
