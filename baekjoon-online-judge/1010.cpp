#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;

        vector<vector<int> > D(n + 1);
        for (int i = 1; i <= n; i++) {
            D[i].resize(m + 1);
        }

        for (int i = 1; i <= n; i++) {
            D[i][i] = 1;
        }
        for (int i = 1; i <= m; i++) {
            D[1][i] = i;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = i + 1; j <= m; j++) {
                D[i][j] = 0;
                for (int k = j - 1; k >= i - 1; k--) {
                    D[i][j] += D[i - 1][k];
                }
            }
        }

        cout << D[n][m] << endl;
    }
}