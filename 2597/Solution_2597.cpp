#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int countBeautifulSubsets(const vector<int>& nums, int k) {
    int n = nums.size();
    int beautifulCount = 0;

    // 生成所有非空子集
    for (int mask = 1; mask < (1 << n); ++mask) {
        vector<int> subset;
        
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }

        // 检查该子集是否美丽
        bool isBeautiful = true;
        for (int i = 0; i < subset.size(); ++i) {
            for (int j = i + 1; j < subset.size(); ++j) {
                if (abs(subset[i] - subset[j]) == k) {
                    isBeautiful = false;
                    break;
                }
            }
            if (!isBeautiful) {
                break;
            }
        }

        if (isBeautiful) {
            beautifulCount++;
        }
    }

    return beautifulCount;
}

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 1;
    cout << "美丽子集的数量: " << countBeautifulSubsets(nums, k) << endl; // 输出美丽子集的数量
    return 0;
}

