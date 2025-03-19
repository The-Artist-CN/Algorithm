#include <algorithm> // 用于 std::sort
#include <vector>
#include <iostream>

using namespace std;

int maximumProduct(vector<int>& nums) {
    // 打印 nums 的地址
    cout << "Address of nums in maximumProduct: " << &nums << endl;

    // 打印 nums 中第一个元素的地址
    if (!nums.empty()) {
        cout << "Address of first element in nums: " << &nums[0] << endl;
    }

    // 对 nums 进行排序
    sort(nums.begin(), nums.end());

    int n = nums.size();

    // 计算最大乘积
    int result = max((nums[n - 1] * nums[n - 2] * nums[n - 3]), (nums[0] * nums[1] * nums[n - 1]));

    return result;
}

vector<int> sortVector(vector<int> v) {
    // 打印 v 的地址
    cout << "Address of v in sortVector: " << &v << endl;

    // 打印 v 中第一个元素的地址
    if (!v.empty()) {
        cout << "Address of first element in v: " << &v[0] << endl;
    }

    // 对 v 进行排序
    sort(v.begin(), v.end());

    return v;
}

int main() {
    vector<int> nums = {-4, -3, -2, -1, 60, 50, 40, 30};

    // 打印 nums 的地址
    cout << "Address of nums in main: " << &nums << endl;

    // 打印 nums 中第一个元素的地址
    if (!nums.empty()) {
        cout << "Address of first element in nums: " << &nums[0] << endl;
    }

    // 调用 maximumProduct 函数
    cout << "Maximum product: " << maximumProduct(nums) << endl;

    // 调用 sortVector 函数
    vector<int> sortednums = sortVector(nums);

    // 打印排序后的 nums
    cout << "Sorted nums: ";
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;

    // 打印 sortednums
    cout << "Sortednums: ";
    for (int i : sortednums) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
