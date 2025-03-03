#include <iostream>

using namespace std;

bool isPowerOfFour( int num ){
    if ( num <= 0 ) return false;

    while ( num % 4 == 0 ){
        num /= 4;
    }

    return num == 1;
    
}

int main() {
    cout << isPowerOfFour(16) << endl;  // 输出: 1 (true)
    cout << isPowerOfFour(5) << endl;   // 输出: 0 (false)
    cout << isPowerOfFour(1) << endl;   // 输出: 1 (true)
    return 0;
}
