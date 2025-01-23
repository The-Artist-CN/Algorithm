#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// 计算范德蒙德矩阵的行列式
double vandermondeDeterminant(const vector<double>& x) {
    int n = x.size();
    double det = 1.0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            det *= (x[j] - x[i]);
        }
    }

    return det;
}

// 生成范德蒙德矩阵
vector<vector<double>> generateVandermondeMatrix(const vector<double>& x) {
    int n = x.size();
    vector<vector<double>> V(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            V[i][j] = pow(x[i], j);
        }
    }

    return V;
}

// 打印矩阵
void printMatrix(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector<vector<double>> V = generateVandermondeMatrix(x);

    cout << "范德蒙德矩阵:" << endl;
    printMatrix(V);

    double det = vandermondeDeterminant(x);

    cout << "行列式 = " << det << endl;

    return 0;
}

