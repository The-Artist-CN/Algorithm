#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution_455 {
public:
    int findContentChildren( vector<int>& c , vector<int>& s ){

        sort(c.begin() , c.end());
        sort(s.begin() , s.end());

        int child = 0;
        int cookie = 0;

        while (child < c.size() && cookie < s.size()){
            if (c[child] <= s[child]){
                child++;
            }

            cookie++;
        }

        return child;
    }

};



int main() {
    // 测试用例
    vector<int> g = {1, 2, 3}; // 孩子的胃口值
    vector<int> s = {1, 1};    // 饼干的尺寸
    Solution_455 ss;

    // 输出满足的孩子数
    cout << ss.findContentChildren(g, s) << endl; // 输出：1

    return 0;
}
