
#include <string>

class Solution_434 {
private:
    int count = 0;
public:
    int countSegment(std::string& s){
        
        for (int i = 0 ; i < s.size() ; i++){
            if ((i==0 || s[i-1] == ' ') && s[i] != ' '){
                count++;
            }
        }

        return count;
    } 
};

