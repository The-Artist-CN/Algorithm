#include <vector>
#include <iostream>

using namespace std;

class First {
public:
    vector<int> getRow(int number){
        vector<int> dp( number + 1 , 1 );
        for (int i = 1; i <= number; ++i) {
            for (int j = i - 1; j > 0; --j) {
                dp[j] += dp[j - 1];
            }
        }

        return dp;
    }
};


//Apr 3 7:00AM

class Second {
public:
    vector<int> getRow(int num){
        vector<vector<int>> result(num + 1);
        for (int i = 0;i <= num ; i++){
            result[i].resize(i+1);
            result[i][0] = result[i][i] = 1;
            for (int j = 1 ; j < i ; j++){
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }

        return result[num];
    }
};


int main(){
    Second second;
    int n;
    cin >> n;
    vector<int> result = second.getRow(n);
    for ( int r : result ){
        cout << r << " ";
    }

    
    return 0;
}
