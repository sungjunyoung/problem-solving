//
// Created by 성준영 on 2017. 8. 30..
//


#include <iostream>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        string s;
        cin >> s;

        int a = s[0] - '0';

        int b = s[2] - '0';
        cout << a + b << endl;
    }
}