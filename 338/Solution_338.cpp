#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int n) {
    vector<int> bits(n+1, 0);

    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            bits[i] = bits[i-1] + 1;
        } else {
            bits[i] = bits[i>>1];
        }
    }

    return bits;
}

int main() {
    vector<int> result = countBits(15);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
