#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1 , vector<int>& nums2){
    stack<int> s;
    unordered_map<int,int> n;

    for ( int num : nums2 ){
        while (!s.empty() && num > s.top()){
            n[s.top()] = num;
            s.pop();
        }
        s.push(num);
    }

    while (!s.empty()){
        n[s.top()] = -1;
        s.pop();
    }

    vector<int> result;
    
    for(int num : nums1){
        result.push_back(n[num]);
    }

    return result;
}


int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = nextGreaterElement(nums1, nums2);

    for (int num : result) {
        cout << num << " "; // 输出：-1 3 -1
    }

    return 0;
}
