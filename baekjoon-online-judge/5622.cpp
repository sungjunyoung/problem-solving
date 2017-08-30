#include <iostream>

using namespace std;

int getNum(char a) {
    if (a - 0 >= 65 && a - 0 <= 67) {
        return 3;
    } else if (a - 0 >= 68 && a - 0 <= 70) {
        return 4;
    } else if (a - 0 >= 71 && a - 0 <= 73) {
        return 5;
    } else if (a - 0 >= 74 && a - 0 <= 76) {
        return 6;
    } else if (a - 0 >= 77 && a - 0 <= 79) {
        return 7;
    } else if (a - 0 >= 80 && a - 0 <= 83) {
        return 8;
    } else if (a - 0 >= 84 && a - 0 <= 86) {
        return 9;
    } else if (a - 0 >= 87 && a - 0 <= 90) {
        return 10;
    }

}

int main() {
    string s;
    cin >> s;

    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += getNum(s[i]);
    }

    cout << sum;

}