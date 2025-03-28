#include <iostream>

class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        for(int k = i; k <= j; k++){
            if(M & (1 << (k - i))){
                N |= (1 << k);
            }else if(!(M & (1 << (k - i)))){
                if(N & (1 << k)){
                    N ^= (1 << k);
                }
            }
        }
        return N;
    }
};

作者：KeepTryingGo
链接：https://leetcode.cn/problems/insert-into-bits-lcci/solutions/3046215/mian-shi-ti-0501cha-ru-wei-yun-suan-cao-vgeux/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main() {
    int N = 1024; // 二进制: 10000000000
    int M = 19;   // 二进制: 00000000001 0011
    int i = 2;
    int j = 6;

    Solution solution;
    int result = solution.insertBits(N, M, i, j);
    std::cout << "Result: " << result << std::endl; // 输出结果

    return 0;
}

