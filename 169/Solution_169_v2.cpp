#include <iostream>
#include <unordered_map>
#include <vector>

int majorityElement(std::vector<int>& nums){
    std::unordered_map<int,int> map;
    int max_number;

    for (int i = 0 ; i < nums.size() ; i++){
        map[nums[i]]++;
    }

    for (const auto p : map){
        if (p.second > nums.size()/2){
            return p.first;
        }
    }

    return 0;
}


int main(){
    std::vector<int> v = {2,2,2,1,1,1,2,2,1,1,2};

    int result = majorityElement(v);
    std::cout << "The result is : " << result << std::endl;
    return 0;
}
