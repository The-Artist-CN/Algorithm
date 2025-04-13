#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>  // For std::upper_bound

bool isSubsequenceUseDoublePointer(const std::string& s, const std::string& t) {
    int is = 0, it = 0;
    while (is < s.size() && it < t.size()) {
        if (s[is] == t[it]) {
            is++;
        }
        it++;
    }
    return is == s.size();
}

std::unordered_map<char, std::vector<int>> preprocess(const std::string& t) {
    std::unordered_map<char, std::vector<int>> charPositions;
    for (int i = 0; i < t.size(); i++) {
        charPositions[t[i]].push_back(i);
    }
    return charPositions;
}

bool isSubsequenceUseDp(const std::string& s, const std::unordered_map<char, std::vector<int>>& charPositions, const std::string& t) {
    int cur = -1;
    for (char c : s) {
        if (charPositions.find(c) == charPositions.end()) return false;
        const auto& positions = charPositions.at(c);
        auto it = std::upper_bound(positions.begin(), positions.end(), cur);
        if (it == positions.end()) return false;
        cur = *it;
    }
    return true;
}

int main() {
    std::string t = "abcde";
    auto charPositions = preprocess(t);

    std::string s = "ace";
    if (isSubsequenceUseDp(s, charPositions, t)) {
        std::cout << "\"" << s << "\" is a subsequence of \"" << t << "\" using DP method\n";
    } else {
        std::cout << "\"" << s << "\" is not a subsequence of \"" << t << "\" using DP method\n";
    }

    if (isSubsequenceUseDoublePointer(s, t)) {
        std::cout << "\"" << s << "\" is a subsequence of \"" << t << "\" using double pointer method\n";
    } else {
        std::cout << "\"" << s << "\" is not a subsequence of \"" << t << "\" using double pointer method\n";
    }

    return 0;
}

