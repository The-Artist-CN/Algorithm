

class Solution {
public:
    void merge(std::vector<int>& num1 , int n ,  std::vector<int>& num2 , int m){
        for (int i = 0 ; i < n ; i++){
            num1[n+i] = num2[i];
        }
        std::sort(num1.begin(),num1.end());
    }

    void Merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0 , p2 = 0;
        int result[m + n];
        int cur;
        while (p1 < m || p2 < n){
            if (p1 == m){
                cur = nums2[p2++];
            } else if (p2 == n){
                cur = nums1[p1++];
            } else if (nums1[p1] < nums2[p2]){
                cur = nums1[p1++];
            } else {
                cur = nums2[p2++];
            }
            result[p1+p2-1] = cur;
        }
        for (int i = 0 ; i < m + n ; i++){
            nums1[i] = result[i];
        }
    }
}
