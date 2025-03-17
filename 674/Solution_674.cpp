#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findLength(std::vector<int>& v){
        if (v.empty()) return 0;

        int current = 1;
        int maxcount = 1;

        for ( int i = 1 ; i < v.size() ; i++ ){
            if (v[i] > v[i-1]){
                current++;
            } else {
                current = 1;
            }
            maxcount = std::max(maxcount,current);
        }

        return maxcount;
    }

};


int main(){
    Solution solution;
    std::vector<int> v1 = {1,3,5,6,7,8,2,1,3,4,5,6,7,8,9,10,11,23};
    std::cout << "最长连续递增子序列长度: " << solution.findLength(v1) << std::endl;
    return 0;
}
