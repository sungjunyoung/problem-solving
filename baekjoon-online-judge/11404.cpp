#include <iostream>

using namespace std;
const int MAX = 10000000;

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    int table[101][101];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            table[i][j] = MAX;
            if (i == j) {
                table[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < table[a][b])
            table[a][b] = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (table[i][k] + table[k][j] < table[i][j])
                    table[i][j] = table[i][k] + table[k][j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << table[i][j] << " ";
        }
        if (i != n)
            cout << endl;
    }

    return 0;
}