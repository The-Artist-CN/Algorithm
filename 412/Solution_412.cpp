#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> fizzBuzz( int n ){
    vector<string> answer;
    for ( int i = 1 ; i <= n ; i++){
        if ( i % 3 == 0 && i % 5 == 0 ){
            answer.push_back("FizzBuzz");
        } else if (i % 3 == 0) {
            answer.push_back("Fizz"); // 是 3 的倍数
        } else if (i % 5 == 0) {
            answer.push_back("Buzz"); // 是 5 的倍数
        } else {
            answer.push_back(to_string(i)); // 既不是 3 的倍数也不是 5 的倍数
        }
    }

    return answer;
}


int main() {
    int n = 15; // 示例输入
    vector<string> result = fizzBuzz(n);

    // 输出结果
    for (const string& str : result) {
        cout << str << endl;
    }

    return 0;
}
