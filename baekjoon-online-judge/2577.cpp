//
// Created by 성준영 on 2017. 4. 12..
//

#include <iostream>

using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    int mul = a * b * c;

    int countList[10];
    for (int i = 0; i <= 9; i++) {
        countList[i] = 0;
    }

    while (mul != 0) {
        int temp = mul % 10;
        countList[temp]++;
        mul = mul / 10;
    }

    for (int i = 0; i <= 9; i++) {
        cout << countList[i] << endl;
    }
}