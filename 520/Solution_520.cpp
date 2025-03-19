#include <cctype>
#include <iostream>
#include <string>
using namespace std;

bool detectCapitalUse(std::string str){
    int n = str.length();

    bool allUpper = true;

    for (char c : str){
        if (!isupper(c)){
            allUpper = false;
            break;
        }
    }

    if (allUpper) return true;

    bool allLower = true;

    for (char c : str) {
        if (!islower(c)) {
            allLower = false;
            break;
        }
    }

    if (allLower) return true;

    if (isupper(str[0])){
        bool restLower = true;
        for (int i = 1 ; i < n ; i++){
            if (!islower(str[i])){
                restLower = false;
                break;
            }
        }

        if (restLower) return true;
    }

    return false;
}


int main() {
    cout << boolalpha; // 输出 true/false 而不是 1/0
    cout << detectCapitalUse("USA") << endl;      // 输出: true
    cout << detectCapitalUse("leetcode") << endl; // 输出: true
    cout << detectCapitalUse("Google") << endl;   // 输出: true
    cout << detectCapitalUse("FlaG") << endl;     // 输出: false
    return 0;
}
