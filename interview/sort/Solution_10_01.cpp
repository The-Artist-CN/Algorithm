#include <iostream>
#include <vector>

using namespace std;

void mergeUseReverseDoublePoint(vector<int>& a , int la , vector<int>& b , int lb){
    int i = la - 1;
    int j = lb - 1;
    int k = la + lb - 1;

    while (i >= 0 && j >= 0){
        if (a[i] > b[j]){
            a[k--] = a[i--];
        } else {
            a[k--] = b[j--];
        }
    }

    while (j >= 0){
        a[k--] = b[j--];
    }
}

void mergeUseDirect(vector<int>& A, int m, vector<int>& B, int n) {
    for (int i = 0; i != n; ++i) {
        A[m + i] = B[i];
    }
    sort(A.begin(), A.end());
}



int main() {
    // 测试用例
    vector<int> A = {1, 2, 3, 0, 0, 0}; // A 的有效部分是 {1, 2, 3}
    int m = 3;
    vector<int> B = {2, 5, 6}; // B 的有效部分是 {2, 5, 6}
    int n = 3;

    mergeUseReverseDoublePoint(A, m, B, n);

    // 输出结果
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
