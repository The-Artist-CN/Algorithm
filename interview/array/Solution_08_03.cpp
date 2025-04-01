#include <vector>


using namespace std;

class Solution {
public:
    int getAnswer(vector<int>& nums, int left, int right) {
        if (left > right) {
            return -1;
        }
        int mid = (right - left) / 2 + left;
        int leftAnswer = getAnswer(nums, left, mid - 1);
        if (leftAnswer != -1) {
            return leftAnswer;
        } else if (nums[mid] == mid) {
            return mid;
        }
        return getAnswer(nums, mid + 1, right);
    }

    int findMagicIndex(vector<int>& nums) {
        return getAnswer(nums, 0, (int) nums.size() - 1);
    }
};

