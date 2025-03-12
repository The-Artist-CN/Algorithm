#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;  // 存储所有有效分数
        
        for (const string& op : operations) {
            if (op == "+") {
                // 新得分是前两轮得分的总和
                scores.push_back(scores[scores.size()-1] + scores[scores.size()-2]);
            }
            else if (op == "D") {
                // 新得分是前一轮得分的两倍
                scores.push_back(2 * scores.back());
            }
            else if (op == "C") {
                // 取消前一轮得分
                scores.pop_back();
            }
            else {
                // 将字符串转换为整数并添加新得分
                scores.push_back(stoi(op));
            }
        }
        
        // 计算总得分
        return accumulate(scores.begin(), scores.end(), 0);
    }
};

int main(){
    Solution solution;
    std::vector<std::string> operations = {"5","2","C","D","+"};
    int result = solution.calPoints(operations);
    std::cout << "Total score: " << result << std::endl;
    return 0;
}