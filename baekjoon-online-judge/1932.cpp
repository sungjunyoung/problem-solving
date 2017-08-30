//
// Created by 성준영 on 2017. 5. 16..
//

#include <cstring>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a[501][501];
int d[501][501];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    memset(d, -1, sizeof(d));
    d[1][1] = a[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if(i==j){
                d[i][j] = d[i-1][j-1] + a[i][j];
            } else if (j == 1){
                d[i][j] = d[i-1][1] + a[i][j];
            } else {
                d[i][j] = max(d[i-1][j-1], d[i-1][j])  + a[i][j];
            }
        }
    }

    int max = 0;
    for(int i=1;i<=n;i++){
        if(max <= d[n][i]){
            max = d[n][i];
        }
    }
    cout << max << endl;

}