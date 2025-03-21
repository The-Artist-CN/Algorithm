#include <iostream>
#include <string>
#include <bitset>

using namespace std;

bool isUnique(string str) {
    int check = 0;
    bool isUnique = true;  // 假设字符串是唯一的
    for (char c : str) {
        int n = c - 'a';
        if ((check & (1 << n)) > 0) {
            cout << "Duplicate character: " << c << " (" << n << ")" << endl;
            isUnique = false;  // 标记为不唯一
        }
        check |= (1 << n);  // 更新 check
        cout << "Character: " << c << " (" << n << "), check (binary): " << bitset<32>(check) << endl;
    }
    return isUnique;
}

int main() {
    string s = "abcdefghijklmnopqrstuvwxyza";
    cout << "Is unique: " << isUnique(s) << endl;
    return 0;
}
