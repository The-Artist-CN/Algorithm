class Solution {
public:
    bool canJump(vector<int>& nums){
        int k = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            int temp = i + nums[i];
            k = max(k,temp);
            if (k >= nums.size()-1) return true;
        }
        return false;
    }
}
