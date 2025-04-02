#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int n) {
    if (n == 0) return {};
    vector<vector<int>> result(n);
    for (int i = 0; i < n; i++) {
        result[i].resize(i + 1, 1);  
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];  
        }
    }
    return result;
}

int main() {
    vector<vector<int>> result = generate(5);
    for (vector<int> v : result) {
        for (int num : v) {  
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
