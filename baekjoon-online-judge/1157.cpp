#include <iostream>

using namespace std;

int main() {
    int list[26];

    for (int i = 0; i < 26; i++) {
        list[i] = 0;
    }

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] - 0 >= 65 && s[i] - 0 <= 90) {
            // 대문자
            list[s[i] - 65]++;
        } else {
            list[s[i] - 97]++;
        }
    }


    int max = 0;
    for (int i = 0; i < 26; i++) {
        if(max < list[i]){
            max = list[i];
        }
    }

    int count = 0;
    int resultInt;
    for (int i = 0; i < 26; i++) {
        if(max == list[i]){
            resultInt = i;
            count ++;
        }
    }

    if(count > 1){
        cout << "?" << '\n';
    } else {
        cout << char(resultInt+65) << '\n';
    }
}