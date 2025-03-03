#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int findShortestSubarray(vector<int>& nums) {
    unordered_map<int, int> count; // 记录出现频率
    unordered_map<int, int> first; // 记录首次出现的索引
    unordered_map<int, int> last;  // 记录最后一次出现的索引
    
    for (int i = 0; i < nums.size(); ++i) {
        count[nums[i]]++;
        if (first.find(nums[i]) == first.end()) {
            first[nums[i]] = i; // 记录首次出现位置
        }
        last[nums[i]] = i; // 更新最后出现位置
    }
    
    int degree = 0;
    for (const auto& entry : count) {
        degree = max(degree, entry.second); // 找到最大频率
    }
    
    int minLength = nums.size();
    for (const auto& entry : count) {
        if (entry.second == degree) {
            int length = last[entry.first] - first[entry.first] + 1; // 计算子数组长度
            minLength = min(minLength, length); // 更新最小长度
        }
    }
    
    return minLength;
}

