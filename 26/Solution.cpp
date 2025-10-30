class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int prev = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[prev] == nums[i]) {
                continue;
            }
            nums[++prev] = nums[i]; 
        }
        return prev + 1;
    }
};