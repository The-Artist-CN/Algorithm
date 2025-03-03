#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string toHex( int num ){
    if ( num == 0 ){
        return "0";
    }

    const string hexMap = "0123456789abcdef";

    unsigned int n = num;

    string result = "";
    while ( n > 0 ){
        result += hexMap[n%16];
        n /= 16;
    }

    reverse( result.begin() , result.end() );

    return result;

}

int main(){
    cout << toHex(26) << endl;     // 输出: "1a"
    cout << toHex(-1) << endl;     // 输出: "ffffffff"
    cout << toHex(0) << endl;      // 输出: "0"
    cout << toHex(-123) << endl;   // 输出: "ffffff85"
    return 0;
}
