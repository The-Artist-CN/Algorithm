#include <iostream>
#include <vector>
#include <algorithm>  // for std::swap

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            std::swap(s[left++], s[right--]);
        }
    }
};
