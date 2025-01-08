#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = 0; // 不等于 val 的元素计数器

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k] = nums[i]; // 将当前元素放到 k 的位置
            k++; // 增加计数
        }
    }

    return k; // 返回不等于 val 的元素数量
}

int main() {
    vector<int> nums = {3, 2, 2, 3, 4, 5, 3};
    int val = 3;

    int result = removeElement(nums, val);
    cout << "不等于 " << val << " 的元素数量: " << result << endl;

    cout << "更新后的数组: ";
    for (int i = 0; i < result; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}

