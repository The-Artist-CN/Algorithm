/*
给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的 回文串 的长度。

在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int map[52] = {0};
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                map[c - 'a' + 26]++;  // 小写字母映射到26-51
            } else if (c >= 'A' && c <= 'Z') {
                map[c - 'A']++;       // 大写字母映射到0-25
            }
            // 忽略非字母字符（根据题目要求可以添加）
        }
        int length = 0;
        bool hasOdd = false;
        
        for (int count : map) {
            if (count % 2 == 0) {
                length += count;
            } else {
                length += count - 1;
                hasOdd = true;
            }
        }
        
        return length + (hasOdd ? 1 : 0);
    }
};
