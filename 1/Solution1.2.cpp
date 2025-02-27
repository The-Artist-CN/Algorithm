#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashmap; // 用于存储值和索引
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // 计算需要的补数
        if (hashmap.find(complement) != hashmap.end()) { // 检查补数是否存在
            return {hashmap[complement], i}; // 返回补数的索引和当前索引
        }
        hashmap[nums[i]] = i; // 将当前值及其索引存入哈希表
    }
    return {}; // 如果没有找到，返回空
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << result[0] << ", " << result[1] << endl; // 输出 0, 1
    return 0;
}

