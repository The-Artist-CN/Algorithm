#include <iostream>
#include <vector>

using namespace std;


bool canPlaceFlowers(vector<int>& flowers , int n){
    int count = 0;
    int size = flowers.size();

    for (int i = 0 ; i < size ; i++){
        if (flowers[i] == 0){
            bool emptyLeft = (i == 0 || flowers[i-1] == 0);
            bool emptyRight = (i == size-1 || flowers[i+1] == 0);

            if (emptyLeft && emptyRight){
                flowers[i] = 1;
                count++;
            }
        }

        if (count >= n){
            return true;
        }
    }

    return count >= n;
}

int main() {
    // 示例输入
    vector<int> flowerbed = {1, 0, 0, 0, 1, 1, 0, 0, 0, 1};
    int n = 3;

    // 检查是否可以种入 n 朵花
    bool result = canPlaceFlowers(flowerbed, n);

    // 输出结果
    if (result) {
        cout << "可以种入 " << n << " 朵花。" << endl;
    } else {
        cout << "不能种入 " << n << " 朵花。" << endl;
    }

    return 0;
}
