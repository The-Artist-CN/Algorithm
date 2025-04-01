#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;


using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> indexMap; // 存储 list1 中餐厅的名字及其索引
    vector<string> result;
    int minIndexSum = INT_MAX; // 最小索引和

    // 将 list1 中的餐厅存入哈希表
    for (int i = 0; i < list1.size(); ++i) {
        indexMap[list1[i]] = i;
    }

    // 遍历 list2，查找共同餐厅并计算索引和
    for (int j = 0; j < list2.size(); ++j) {
        if (indexMap.find(list2[j]) != indexMap.end()) { // 如果餐厅在 list1 中也存在
            int indexSum = j + indexMap[list2[j]]; // 计算索引和
            if (indexSum < minIndexSum) {
                minIndexSum = indexSum; // 更新最小索引和
                result.clear(); // 清空结果，存入新的餐厅
                result.push_back(list2[j]);
            } else if (indexSum == minIndexSum) {
                result.push_back(list2[j]); // 如果索引和相等，加入结果
            }
        }
    }

    return result;
}

int main() {
    // 示例输入
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};

    // 查找共同喜爱的餐厅
    vector<string> result = findRestaurant(list1, list2);

    // 输出结果
    cout << "共同喜爱的餐厅: ";
    for (const string& restaurant : result) {
        cout << restaurant << " ";
    }
    cout << endl;

    return 0;
}

