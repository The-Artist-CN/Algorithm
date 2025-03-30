#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> result;
        if (k == 0) {
            return result;
        }

        if (shorter == longer) {
            result.push_back(k * shorter);
            return result;
        }

        for (int i = 0; i <= k; i++) {
            int length = i * longer + (k - i) * shorter;
            result.push_back(length);
        }

        // Ensure the results are in ascending order
        if (longer > shorter) {
            // The lengths are already in ascending order (i from 0 to k)
        } else {
            // Need to sort if longer < shorter
            sort(result.begin(), result.end());
        }

        return result;
    }
};
