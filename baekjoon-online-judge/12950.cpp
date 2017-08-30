#include <iostream>

using namespace std;

const char NO = '0';

int main() {
    int n, m;
    cin >> n >> m;

    char table[21][21];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            table[i][j] = NO;
        }
    }

    for (int i = 0, from, to, what; i < m; i++) {
        cin >> from >> to >> what;
        table[from][to] = what;
        table[to][from] = what;
    }

    int D[21][21];
    for (int i = 0; i < n; i++) {
        D[i][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] != NO) {
                D[i][j] = 1;
            }
        }
    }

    return 0;
}