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

int main() {
    std::vector<char> target = {'h','e','l','l','o'};
    Solution solution;
    solution.reverseString(target);
    
    for (char c : target) {
        std::cout << c;
    }
    std::cout << std::endl;
    
    return 0;
}
