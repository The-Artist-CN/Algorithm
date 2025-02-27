#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cctype>
#include <climits>

/*
[char_, count] 是 C++ 中的一种解构绑定语法，用于在范围 for 循环中遍历类似 std::pair 或 std::tuple 类型的元素时，直接将其解构为多个变量。

不过需要注意的是，这种解构语法只有在 C++17 或更高版本中才支持。

在你的代码中，licenseCount 是一个 std::unordered_map<char, int>，它存储了每个字母及其出现的频率。在 for 循环中，[char_, count] 解构了 unordered_map 的键值对，分别将键赋值给变量 char_，将值赋值给变量 count。
*/
using namespace std;

string shortestCompletingWord( string plate , vector<string>& words){
    
    unordered_map<char,int> plateCount;

    for ( char c : plate){
        if ( isalpha(c)){
            plateCount[tolower(c)]++;
        }
    }
    
    string result;

    int min_length = INT_MAX;

    for ( const auto& word : words){
        unordered_map<char,int> wordCount;

        for ( char c : word){
            wordCount[c]++;
        }

        bool isVaild = true;


        for ( const auto& pair : plateCount){
            char char_ = pair.first;
            int count = pair.second;
            if (wordCount[char_] < count){
                isVaild = false;
                break;
            }
            
        }

        if ( isVaild && word.length() < min_length){
            result = word;
            min_length = word.length();
        }
    }

    return result;

}

int main(){
    // 测试用例
    string licensePlate = "aBc 12c";
    vector<string> words = {"abccdef", "caaacab", "cbca"};

    cout << shortestCompletingWord(licensePlate, words) << endl; // 输出 "cbca"
    return 0;
}
