class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<int> set = {'a','e','i','o','u','A','E','I','O','U'};
        vector<int> seq;
        for (int i = 0 ; i < s.length() ; i++){
            if (set.count(s[i])){
                seq.push_back(i);
            }
        }
        int left = 0 , right = seq.size() - 1;
        while (left < right){
            swap(s[seq[left++]],s[seq[right--]]);
        }

        return s;

    }

    string reverseVowelsBetter(string s){
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isVowel(s[left])) left++;
            while (left < right && !isVowel(s[right])) right--;
            swap(s[left++], s[right--]);
        }
        return s;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};