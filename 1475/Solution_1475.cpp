#include <vector>
#include <iostream>

using namespace std;

std::vector<int> finalPrices(std::vector<int>& v){
    int n = v.size();
    std::vector<int> nums(n,0);

    for (int i = 0; i < n ;i++){
        nums[i] = v[i];
        for ( int j = i + 1 ; j < n ; j++ ){
            if (v[j] <= v[i]){
                nums[i] = v[i] - v[j];
                break;
            }
        }
    }
    return nums;
}

void printResult(const vector<int>& prices, const vector<int>& result) {
    cout << "原始价格: [";
    for (int i = 0; i < prices.size(); i++) {
        cout << prices[i];
        if (i < prices.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "折扣后价格: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "详细计算:" << endl;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] == result[i]) {
            cout << "商品 " << i << ": 价格 " << prices[i] << ", 无折扣, 最终价格 " << result[i] << endl;
        } else {
            cout << "商品 " << i << ": 价格 " << prices[i] << ", 折扣 " << (prices[i] - result[i])
                 << ", 最终价格 " << result[i] << endl;
        }
    }
    cout << "------------------------" << endl;
}


int main() {
    // 测试案例1: 题目中的例子
    std::vector<int> prices1 = {8, 4, 6, 2, 3};
    std::vector<int> result1 = finalPrices(prices1);
    cout << "测试案例1:" << endl;
    printResult(prices1, result1);

    // 测试案例2: 所有价格递增
    std::vector<int> prices2 = {1, 2, 3, 4, 5};
    std::vector<int> result2 = finalPrices(prices2);
    cout << "测试案例2 (递增价格):" << endl;
    printResult(prices2, result2);

    // 测试案例3: 所有价格递减
    std::vector<int> prices3 = {5, 4, 3, 2, 1};
    std::vector<int> result3 = finalPrices(prices3);
    cout << "测试案例3 (递减价格):" << endl;
    printResult(prices3, result3);

    // 测试案例4: 相同价格
    std::vector<int> prices4 = {3, 3, 3, 3, 3};
    std::vector<int> result4 = finalPrices(prices4);
    cout << "测试案例4 (相同价格):" << endl;
    printResult(prices4, result4);

    // 测试案例5: 混合情况
    std::vector<int> prices5 = {10, 1, 1, 6};
    std::vector<int> result5 = finalPrices(prices5);
    cout << "测试案例5 (混合情况):" << endl;
    printResult(prices5, result5);

    // 测试案例6: 单个元素
    std::vector<int> prices6 = {5};
    std::vector<int> result6 = finalPrices(prices6);
    cout << "测试案例6 (单个元素):" << endl;
    printResult(prices6, result6);

    return 0;
}
