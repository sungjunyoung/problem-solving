//
// Created by 성준영 on 2017. 4. 12..
//

#include <iostream>

using namespace std;

int d(int n) {
    int res = n;

    while (n != 0) {
        res += n % 10;
        n = n / 10;
    }

    return res;
}

int main() {
    int list[10001];
    for (int i = 1; i <= 10000; i++) {
        list[i] = i;
    }

    for (int i = 1; i <= 10000; i++) {
        if(d(i) > 10000){
            continue;
        }
        list[d(i)] = 0;
    }

    for (int i = 1; i <= 10000; i++) {
        if(list[i] != 0){
            cout << list[i] << endl;
        }
    }

}