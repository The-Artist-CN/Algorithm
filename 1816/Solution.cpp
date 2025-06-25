#include <iostream>
#include <string>
using namespace std;


string truncateSentence( string str , int n ){
    if (str.empty()) return "";
    int len = str.size();
    int end  = len ,count =  0;
    for ( int i = 0 ; i < len ; i++){
        if ( str[i] == ' ' || i == len-1 ){
            count++;
            if ( count == n){
                end = ( i == len - 1) ? len : i;
                break;
            }
        }
    }
    return str.substr(0,end);
}


int main(){
    int x;
    string str = "hello my name is Tom";
    cin >> x;
    string result = truncateSentence(str,x);
    cout << "Truncated String : " << result << endl;

    return 0;
}

