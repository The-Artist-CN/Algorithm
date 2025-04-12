#include <vector>
#include <algorithm>

class Solution {
public:
    int breakfastNumber(std::vector<int>& staple , std::vector<int>& drinks , int x){
        const int MOD = 1e9 + 7;
        std::sort(drinks.begin(),drinks.end());
        int result = 0;
        for (int s : staple){
            if (s > x) continue;

            int remain = x - s;
            auto it = upper_bound(drinks.begin(),drinks.end(),remain);
            int count = it - drinks.begin();
            result = (result + count) % MOD; 
        }

        return result 
    }
}
