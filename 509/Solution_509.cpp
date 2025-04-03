#include <iostream>
#include <vector>

using namespace std;






class First {
public:
    int fib(int n) {
        if (n == 0) return 0;
        vector<int> result(n+1);
        result[0] = 0;
        result[1] = 1;
        for (int i = 2 ; i <= n ;i++){
            result[i] = result[i-1] + result[i-2];
        }

        return result[n];
    }
};

class Second {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        int p = 0, q = 0, r = 1;
        for (int i = 2; i <= n; ++i) {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};

int main(){
    Second second;
    cout << second.fib(5) << endl;
    return 0;
}
