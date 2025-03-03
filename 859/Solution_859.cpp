#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool isbuddyString(string s1 , string s2){
    if ( s1.length() != s2.length() ) return false;
    
    if ( s1 == s2 ){
        unordered_set<char> unique_set(s1.begin(),s1.end());
        return unique_set.size() < s2.size();
    }

    vector<int> diff_indices;
    for ( int i = 0 ; i < s1.length() ; i++ ){
        if (s1[i] != s2[i]){
            diff_indices.push_back(i);
        }
    }

    if (diff_indices.size() != 2) return false;
    
    int i = diff_indices[0] , j = diff_indices[1];
    return s1[i] == s2[j] && s1[j] == s2[i];
}

int main() {
    string s = "ab";
    string goal = "ba";

    if (isbuddyString(s, goal)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
