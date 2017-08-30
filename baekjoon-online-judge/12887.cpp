#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000000;

int main() {
    int n = 2;
    int m;
    cin >> m;
    vector<string> a(n);
    int white = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                white += 1;
            }
        }
    }
    vector<int> d[2];
    for (int i = 0; i < n; i++) {
        d[i].resize(m, MAX);
    }

    for (int i = 0; i < 2; i++) {
        if (a[i][m - 1] == '.') {
            d[i][m - 1] = 1;
        }
    }

    for (int j = m - 2; j >= 0; j--) {
        for (int i = 0; i < 2; i++) {
            if (a[i][j] == '#') {
                continue;
            }
            int right = d[i][j + 1] + 1;
            if(a[1-i][j] != '#'){
                right = min(right,2+d[1-i][j+1]);
            }
            d[i][j] = right;
        }
    }
    cout << white -min(d[0][0],d[1][0]) << '\n';

    return 0;
}