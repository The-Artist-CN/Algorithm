#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result; // 存储最终的区间结果
    if (nums.empty()) return result; // 如果数组为空，直接返回空列表

    int start = nums[0]; // 当前区间的起点
    for (int i = 1; i <= nums.size(); ++i) {
        // 如果到数组末尾，或者当前数字与前一个数字不连续
        if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
            if (start == nums[i - 1]) {
                // 如果区间只有一个数字
                result.push_back(to_string(start));
            } else {
                // 如果区间有多个连续数字
                result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
            }
            // 更新新的区间起点
            if (i < nums.size()) start = nums[i];
        }
    }

    return result;
}

// Mar 18 20:00PM

vector<string> summaryRangesV2(vector<int>& nums){
    vector<string> result;
    if (nums.empty()) return result;

    int start = nums[0];
    for (int i = 1 ; i <= nums.size() ; i++){
        if (i == nums.size() || nums[i] != nums[i-1] + 1){
            if (start == nums[i-1]){
                result.push_back(to_string(nums[i-1]));
            } else {
                result.push_back(to_string(start) + "->" + to_string(nums[i-1]));
            }

            start = nums[i];
        }
    }

    return result;
}

int main() {
    // 测试用例
    vector<int> nums1 = {0, 1, 2, 4, 5, 7};
    vector<int> nums2 = {0, 2, 3, 4, 6, 8, 9};
    vector<int> nums3 = {};
    
    // 输出测试结果
    vector<string> result1 = summaryRanges(nums1);
    vector<string> result2 = summaryRanges(nums2);
    vector<string> result3 = summaryRanges(nums3);

    vector<string> result4 = summaryRangesV2(nums1);
    vector<string> result5 = summaryRangesV2(nums2);
    vector<string> result6 = summaryRangesV2(nums3);

    for (const string& range : result1) cout << range << " ";
    cout << endl;

    for (const string& range : result2) cout << range << " ";
    cout << endl;

    for (const string& range : result3) cout << range << " ";
    cout << endl;

    for (const string& range : result4) cout << range << " ";
    cout << endl;

    for (const string& range : result5) cout << range << " ";
    cout << endl;

    for (const string& range : result6) cout << range << " ";
    cout << endl;

    return 0;
}

