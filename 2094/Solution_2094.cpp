#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> findEvenNumbers(vector<int>& digits) {
    set<int> result; // 用于去重
    int n = digits.size();

    // 遍历所有可能的组合
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                // 确保三个索引不重复（如果 digits 中有重复数字，允许重复使用）
                if (i == j || j == k || i == k) continue;

                // 检查是否满足条件
                int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                if (digits[i] != 0 && num % 2 == 0) { // 无前导零且为偶数
                    result.insert(num);
                }
            }
        }
    }

    // 将结果转换为有序的 vector
    vector<int> sortedResult(result.begin(), result.end());
    return sortedResult;
}

int main() {
    vector<int> digits = {1, 2, 3};
    vector<int> result = findEvenNumbers(digits);

    cout << "满足条件的 3 位偶数有：" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
