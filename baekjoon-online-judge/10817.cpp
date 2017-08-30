//
// Created by 성준영 on 2017. 4. 10..
//

#include <iostream>

using namespace std;

int main() {
    int input[3];

    cin >> input[0] >> input[1] >> input[2];

    int temp = input[0];
    int maxIndex = 0;
    for (int i = 0; i < 3; i++) {
        if (temp < input[i]) {
            temp = input[i];
            maxIndex = i;
        }
    }

    int temp2 = 0;
    for (int i = 0; i < 3; i++) {
        if(i == maxIndex){
            continue;
        }

        if(temp2 < input[i]){
            temp2 = input[i];
        }
    }

    cout << temp2;
}