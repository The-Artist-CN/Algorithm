#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < s.size(); right++) {
            // If the character is already in the set, remove characters from the left
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            // Add the current character to the set
            charSet.insert(s[right]);
            // Update the maximum length
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
    int lofls(string s){
        unordered_set<char> res;
        int left = 0;
        int max_value = 0;

        for (int right = 0 ; right < s.length() ;right++){
            while (res.find(s[right] != res.end())){
                res.erase(s[left]);
                left++;
            }
            res.insert(s[right]);
            max_value = std::max(max_value,right-left+1);
        }

        return max_value;
    }
};
