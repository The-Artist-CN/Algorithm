/*
给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的 回文串 的长度。

在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int longestPalinDrome(string str){
    
    unordered_map<char,int> hashmap;

    for ( char c : str){
        hashmap[c]++;
    }

    int palinDromelength = 0;
    bool oddFound = false;
    
    for ( const auto& pair : hashmap){
        int count = pair.second;
        if ( count % 2 == 0){
            palinDromelength += count;
        } else {
            palinDromelength += count--;
            oddFound = true;
        }
    }

    if ( oddFound ){
        palinDromelength += 1;
    }
    return palinDromelength;
}


int main(){
    string s = "abcccccddeee";
    cout << "最长回文串的长度是: " << longestPalinDrome(s) << endl; // 输出 7
    return 0;
}

