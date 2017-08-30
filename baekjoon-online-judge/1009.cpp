//
// Created by 성준영 on 2017. 4. 10..
//

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        int temp = a;
        for (int j = 0; j < b - 1; j++) {
            a = temp * a % 10;
        }

        if(a == 0){
            cout << 10 << endl;
            continue;
        }

        cout << a << endl;
    }
}