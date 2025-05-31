#include <vector>

using namespace std;

class Solution {

public:
    int maxArea(vector<int>& height){
        int left = 0 , right = height.size() - 1;
        int res = 0;

        while (left < right){
            int ans = min(height[left],height[right]) * (left - right);
            res = max(ans,res);
            if (height[left] <= height[right]){
                left++;
            } else {
                right++;
            }
        }

        return res;
    }
};