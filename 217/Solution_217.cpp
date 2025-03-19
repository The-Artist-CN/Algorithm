#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

bool containDup(vector<int>& nums){
    unordered_set<int> s;
    for (int i : nums){
        if (s.count(i)){
            return true;
        }

        s.insert(i);
    }

    return false;
}

bool containDupUseSort(vector<int>& nums){
    sort(nums.begin(),nums.end());
    for ( int i = 1 ; i < nums.size() ; i++ ){
        if (nums[i] == nums[i-1]){
            return true;
        }
    }

    return false;
}

vector<int> generateRandomArray(int size, int minVal, int maxVal) {
    vector<int> nums(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(minVal, maxVal);
    for (int i = 0; i < size; ++i) {
        nums[i] = dis(gen);
    }
    return nums;
}

int main() {

    int size = 1000000; // 数组大小
    int minVal = 1;     // 最小值
    int maxVal = 100000; // 最大值

    vector<int> nums = generateRandomArray(size, minVal, maxVal);

    auto start = chrono::high_resolution_clock::now();
    bool resultSet = containDup(nums);
    auto end = chrono::high_resolution_clock::now();
    auto durationSet = chrono::duration_cast<chrono::milliseconds>(end - start);
    
    cout << "unordered_set 结果: " << resultSet << "，耗时: " << durationSet.count() << " 毫秒" << endl;

    start = chrono::high_resolution_clock::now();
    bool resultMap = containDupUseSort(nums);
    end = chrono::high_resolution_clock::now();
    auto durationMap = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Sort 结果: " << resultMap << "，耗时: " << durationMap.count() << " 毫秒" << endl;

    return 0;

}
