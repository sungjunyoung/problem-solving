#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1000000007;


int main() {

    int n, k;
    cin >> n >> k;

    int D[11][100001];
    vector<int> a(k + 1);
    for (int i = 1; i <= k; i++) {
        D[0][i] = 0;
        D[1][i] = i;
    }
    for (int i = 1; i <= n; i++) {
        D[i][0] = 0;
    }
    D[1][1] = 1;



    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {

            a.clear();
            for (int x = 1; x * x <= j; x++) {
                if (j % x == 0) {
                    if (x != j / x) {
                        a.push_back(x);
                        a.push_back(j / x);
                    } else {
                        a.push_back(x);
                    }
                }
            }
            int sum = 0;
            for (int x = 0; x < a.size(); x++) {
                if (a[x] != j) {
                    sum += D[i - 1][a[x]] - D[i - 1][a[x] - 1];
                    sum %= MAX;
                    sum += MAX;
                    sum %= MAX;
                }
            }

            D[i][j] = (D[i][j - 1] + D[i - 1][k] - sum) % MAX;
            D[i][j] += MAX;
            D[i][j] %= MAX;

        }
    }
    cout << D[n][k];

    return 0;
}