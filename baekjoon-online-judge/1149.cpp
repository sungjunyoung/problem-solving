//
// Created by 성준영 on 2017. 5. 16..
//

#include <cstring>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[1001][3];
int d[1001][3];

int main() {
    int n;
    cin >> n;

    memset(a, -1, sizeof(a));

    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }

    d[1][0] = a[1][0];
    d[1][1] = a[1][1];
    d[1][2] = a[1][2];

    for (int i = 2; i <= n; i++) {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];
    }

    cout << min(min(d[n][0], d[n][1]),d[n][2]) << endl;
}