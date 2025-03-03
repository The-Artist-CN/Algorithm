#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int numJewelsInStones(string jewels, string stones) {
    // 使用 unordered_set 存储宝石类型
    unordered_set<char> jewelSet(jewels.begin(), jewels.end());

    int count = 0;
    // 遍历 stones，统计宝石的数量
    for (char stone : stones) {
        if (jewelSet.count(stone)) {
            count++;
        }
    }

    return count;
}

int main() {
    string jewels = "aA";
    string stones = "aAAbbbb";
    cout << "宝石数量: " << numJewelsInStones(jewels, stones) << endl; // 输出 3

    jewels = "z";
    stones = "ZZ";
    cout << "宝石数量: " << numJewelsInStones(jewels, stones) << endl; // 输出 0

    return 0;
}

