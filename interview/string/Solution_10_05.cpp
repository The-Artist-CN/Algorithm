#include <vector>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int findString(vector<string>& words, string s) {
        int left = 0;
        int right = words.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (words[mid] == "") {
                int p = mid - 1, q = mid + 1;
                while (true) {
                    if (p < left && q > right) return -1;
                    if (p >= left && words[p] != "") {
                        mid = p;
                        break;
                    } else if (q <= right && words[q] != "") {
                        mid = q;
                        break;
                    }
                    p--;
                    q++;
                }
            }

            if (words[mid] == s) {
                return mid;
            } else if (words[mid] < s) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

void testFindString() {
    Solution sol;
    
    // 示例1
    vector<string> words1 = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    assert(sol.findString(words1, "ta") == -1);
    
    // 示例2
    vector<string> words2 = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    assert(sol.findString(words2, "ball") == 4);
    
    // 所有空字符串
    vector<string> words3 = {"", "", "", ""};
    assert(sol.findString(words3, "test") == -1);
    
    // 目标字符串在开头
    vector<string> words4 = {"apple", "", "", "banana", "", "cherry"};
    assert(sol.findString(words4, "apple") == 0);
    
    // 目标字符串在末尾
    vector<string> words5 = {"apple", "", "", "banana", "", "cherry"};
    assert(sol.findString(words5, "cherry") == 5);
    
    // 中间有空字符串
    vector<string> words6 = {"apple", "", "", "banana", "", "cherry"};
    assert(sol.findString(words6, "banana") == 3);
    
    // 空数组
    vector<string> words7;
    assert(sol.findString(words7, "test") == -1);
    
    // 单个非空字符串
    vector<string> words8 = {"", "", "test", "", ""};
    assert(sol.findString(words8, "test") == 2);
    
    cout << "所有测试用例通过！" << endl;
}

int main() {
    testFindString();
    return 0;
}
