//
// Created by 성준영 on 2017. 9. 29..
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int aSize = a.size();
    int bSize = b.size();

    vector<vector<int> > D(bSize + 1);
    for (int i = 0; i <= bSize; i++) {
        D[i].resize(aSize + 1);
    }

    for (int i = 1; i <= bSize; i++) {
        for (int j = 1; j <= aSize; j++) {
            if (a[j - 1] == b[i - 1]) {
                D[i][j] = D[i - 1][j - 1] + 1;
            } else {
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
            }
        }
    }

    cout << D[bSize][aSize] << endl;

    int curPosA = aSize;
    int curPosB = bSize;
    string result;
    while (D[curPosB][curPosA] != 0) {
        if (a[curPosA - 1] == b[curPosB - 1]) {
            result += a[curPosA - 1];
            curPosA -= 1;
            curPosB -= 1;
        } else if (D[curPosB][curPosA - 1] == D[curPosB][curPosA]) {
            curPosA -= 1;
        } else if (D[curPosB - 1][curPosA] == D[curPosB][curPosA]) {
            curPosB -= 1;
        }
    }

    for (int i = result.size() - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");
}