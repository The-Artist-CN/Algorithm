#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int halfQuestions(vector<int>& questions) {
    int N = questions.size() / 2; // 需要选择的题目数量
    unordered_map<int, int> freq; // 统计每种知识点类型的频率

    // 统计每种知识点类型出现的次数
    for (int question : questions) {
        freq[question]++;
    }

    // 将频率存入一个数组，并按降序排序
    vector<int> counts;
    for (auto& pair : freq) {
        counts.push_back(pair.second);
    }
    sort(counts.rbegin(), counts.rend()); // 从大到小排序

    // 选择题目，统计需要的知识点种类数
    int selected = 0; // 已选择的题目数量
    int knowledgeTypes = 0; // 知识点类型数量
    for (int count : counts) {
        selected += count; // 选择当前知识点的所有题目
        knowledgeTypes++; // 增加一种知识点类型
        if (selected >= N) break; // 如果选择的题目数量达到 N，停止
    }

    return knowledgeTypes;
}

int main() {
    // 测试用例
    vector<int> questions1 = {2, 2, 3, 3, 2, 4, 4, 4};
    cout << halfQuestions(questions1) << endl; // 输出 2

    vector<int> questions2 = {1, 1, 2, 2, 3, 3};
    cout << halfQuestions(questions2) << endl; // 输出 3

    return 0;
}
