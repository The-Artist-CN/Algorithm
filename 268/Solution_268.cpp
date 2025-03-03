#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int missingNumberV1(vector<int>& nums){
    int n = nums.size();
    int sum = n * (n + 1) / 2;
    int arraySum = 0;
    for ( int num : nums ){
        arraySum+=num;
    }

    return sum - arraySum;
}

int missingNumberV2(vector<int>& nums){
    sort(nums.begin(), nums.end()); // 排序数组
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != i) { // 如果数字不等于索引，返回索引
            return i;
        }
    }
    return nums.size(); // 如果没有缺失，返回 n
}

int missingNumberV3(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end()); // 将数组存入哈希表
    for (int i = 0; i <= nums.size(); i++) {
        if (numSet.find(i) == numSet.end()) { // 如果哈希表中找不到数字 i
            return i;
        }
    }
    return -1; // 不会到达这里
}


int missingNumberV4(vector<int>& nums) {
    int n = nums.size();
    int result = 0;
    // 对 [0, n] 的数字进行异或
    for (int i = 0; i <= n; i++) {
        result ^= i;
    }
    // 对数组中的数字进行异或
    for (int num : nums) {
        result ^= num;
    }
    return result; // 缺失的数字
}

int main() {
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << "缺失的数字是: " << missingNumberV1(nums) << endl; // 输出 8
    return 0;
}

