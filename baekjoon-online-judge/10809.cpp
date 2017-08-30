#include <iostream>
#include <string>

using namespace std;


int main() {
    string s;
    cin >> s;

    int result[26];
    for (int i = 0; i < 26; i++) {
        result[i] = -1;
    }

    for (int i = 0; i < s.length(); i++) {

//        cout << s[i]-97 << '\n';
        if(result[s[i] - 97] == -1){
            result[s[i] - 97] = i;
        }

    }

    for (int i = 0; i < 26; i++) {
        cout << result[i] << " ";
    }
}