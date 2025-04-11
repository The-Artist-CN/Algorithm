

class Solution {
public:
    void merge(std::vector<int>& num1 , int n ,  std::vector<int>& num2 , int m){
        for (int i = 0 ; i < n ; i++){
            num1[n+i] = num2[i];
        }
        std::sort(num1.begin(),num1.end());
    }

    void merge_v2(std::vector<int>& num1 , int n ,  std::vector<int>& num2 , int m){
        int p = n - 1 , q = m - 1;
        int tail = n + m - 1;
        int cur;
        while (p >= 0 || q >= 0){
            if (p==-1){
                cur = num2[q--];
            } else if (q==-1){
                cur = num1[p--];
            } else if (num1[p] > num2[q]){
                cur = num1[p--];
            } else {
                cur = num2[q--];
            }
            
            num1[tail--] = cur;
        }
    }
}
