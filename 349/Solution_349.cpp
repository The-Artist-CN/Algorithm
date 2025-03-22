#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>



using namespace std;

vector<int> intersection(vector<int>& nums1 , vector<int>& nums2){

    unordered_set<int> us(nums1.begin(),nums1.end());
    unordered_set<int> result;

    for (int num : nums2){
        if (us.count(num)){
            result.insert(num); 
        }
    }

    vector<int> re(result.begin(),result.end());
    return re;
}



vector<int> intersectionV2(vector<int>& nums1 , vector<int>& nums2){
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());

    int i = 0 , j = 0;
    vector<int> result;
    
        // 双指针遍历
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            // 找到交集元素
            if (result.empty() || nums1[i] != result.back()) {
                result.push_back(nums1[i]);
            }
            i++;
            j++;
        }
    }

    return result;

}


int main() {
    vector<int> nums1 = {1, 2, 2, 1 , 3, 5, 7};
    vector<int> nums2 = {1, 2, 2 , 5};
    vector<int> result = intersection(nums1, nums2);
    vector<int> resultV2 = intersectionV2(nums1, nums2);

    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    for (int num : resultV2) {
        cout << num << " ";
    }
    return 0;
}
