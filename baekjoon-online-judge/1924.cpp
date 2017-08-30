//
// Created by 성준영 on 2017. 4. 10..
//

#include <iostream>

using namespace std;


int main() {
    int x, y;
    cin >> x >> y;

    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int sum = 0;
    for (int i = 1; i <= 12; i++) {
        if (i == x) {
            break;
        }
        sum = sum + months[i];
    }

    sum = sum + y;

    switch (sum % 7) {
        case 0 :
            cout << "SUN";
            break;
        case 1 :
            cout << "MON";
            break;
        case 2 :
            cout << "TUE";
            break;
        case 3 :
            cout << "WED";
            break;
        case 4 :
            cout << "THU";
            break;
        case 5 :
            cout << "FRI";
            break;
        case 6 :
            cout << "SAT";
            break;
    }


}