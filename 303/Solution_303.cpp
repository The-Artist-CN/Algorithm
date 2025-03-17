#include <iostream>
#include <vector>

class NumArray {
private:
    std::vector<int> prefixSum;

public:

    NumArray(std::vector<int>& nums){
        prefixSum.resize(nums.size()+1,0);
        for (int i = 0 ; i < nums.size() ; i++){
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
    }

    int sumRange( int left , int right ){
        return prefixSum[right+1] - prefixSum[left];
    }

    std::vector<int> getPrefixSum() const {
        return prefixSum;
    }
};

int main(){
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray na(nums);

    std::cout << na.sumRange(0,2) << std::endl;
    std::cout << na.sumRange(2,5) << std::endl;
    std::cout << na.sumRange(0,5) << std::endl;

    for (int i : nums){
        std::cout << i << " ";
    }

    std::cout << std::endl;

    for (int j : na.getPrefixSum()){
        std::cout << j << " ";
    }

    return 0;
}
