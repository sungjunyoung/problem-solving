#include <iostream>

using namespace std;

int main() {
    int d[301][301];
    int i;

    d[1][1] = 0;
    d[1][2] = d[2][1] = 1;
    for (i = 1; i <= 300; i++) {
        d[1][i] = i - 1;
    }

    int n, m;
    cin >> n >> m;

    for (i = 2; i <= n; i++) {
        d[i][m] = d[i/2][m] + d[i-i/2][m] +1;
    }

    cout << d[n][m] << endl;


    return 0;
}