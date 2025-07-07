#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;


class Solution {

public:
    bool wordPattern(const string &pattern , const string &str){
        vector<string> words;
        stringstream ss(str);
        string word;

        while (ss >> word){
            words.push_back(word);
        }

        if (words.size() != pattern.size()) return false;

        unordered_map<char, int> charToIndex;
        unordered_map<string, int> stringToIndex;

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string w = words[i];
            
            // 检查字符和单词的映射是否一致
            if (charToIndex.find(c) == charToIndex.end()) {
                charToIndex[c] = i;
            }
            if (wordToIndex.find(w) == wordToIndex.end()) {
                wordToIndex[w] = i;
            }
            
            if (charToIndex[c] != wordToIndex[w]) {
                return false;
            }
        }
        
        return true;

    }

};



