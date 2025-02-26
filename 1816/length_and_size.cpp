#include <iostream>
#include <string>
using namespace std;

void truncateSentence(string s ,int k){
    int num = s.size();
    int len = s.length();
    cout << ((num == len) ? "num:"+  to_string( num) + "len:" + to_string( len) : "not equal!") << endl;

}

int main(){
    string str = "Hello how are you Contestant";
    truncateSentence(str,0);
    return 0;
}
