//
// Created by 성준영 on 2017. 4. 12..
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    float list[1001];

    for (int i = 1; i <= n; i++) {
        cin >> list[i];
    }

    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (max < list[i]) {
            max = list[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        list[i] = list[i]/max*100;
    }

    float sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += list[i];
    }

    printf("%.2f", (sum / n));
}