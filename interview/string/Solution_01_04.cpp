#include <iostream>
#include <string>

bool canPermutePalindrome(const std::string& s) {
    int bitVector = 0;
    
    // 遍历字符串中的每个字符
    for (char c : s) {
        // 使用异或运算翻转对应的位
        bitVector ^= (1 << (c - 'a'));
    }
    
    // 检查 bitVector 是否只有一个或零个 1
    return (bitVector & (bitVector - 1)) == 0;
}

int main() {
    std::string input = "tactcoa";
    if (canPermutePalindrome(input)) {
        std::cout << "true" << std::endl; // 输出 true
    } else {
        std::cout << "false" << std::endl; // 输出 false
    }
    
    return 0;
}

