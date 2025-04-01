
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>


using namespace std;

vector<int> calculateHitAndPseudoHit(const string& solution , const string& guess){
    int hit = 0;
    int pseudo_hit = 0;

    unordered_map<char,int> count_solution;
    unordered_map<char,int> count_guess;

    for (int i = 0 ; i < solution.size() ; i++){
        if (solution[i] == guess[i]){
            hit++;
        } else {
            count_solution[solution[i]]++;
            count_guess[solution[i]]++;
        }
    }

    for (const auto& pair : count_solution){
        char color = pair.first;
        pseudo_hit += min(count_solution[color],count_guess[color]);
    }

    return {hit,pseudo_hit};
}

int main(){

    string solution = "RGGB";
    string guess = "YRGB";

    vector<int> result = calculateHitAndPseudoHit(solution, guess);

    cout << "Hit: " << result[0] << ", Pseudo-hit: " << result[1] << endl;
    return 0;
}
