#include <iostream>

using namespace std;

string defaultIPV4(string str){
    string result;

    for ( char c : str){
        if ( c == '.'){
            result += "[.]";
        } else {
            result += c;
        }
    }
    return result;
}

int main(){
    string ip = "192.168.1.100";
    cout << defaultIPV4(ip) << endl;
    return 0;
}
