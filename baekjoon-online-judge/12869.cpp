#include <iostream>
#include <cstring>

using namespace std;

int d[61][61][61];

int go(int i, int j, int k) {
    if (i < 0) i = 0;
    if (j < 0) j = 0;
    if (k < 0) k = 0;
    d[i][j][k] = 1;




}

int main(void) {
    int n;
    int a[3] = {0, 0, 0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(d, -1, sizeof(d));
    cout << go(a[0], a[1], a[2]) << endl;

    return 0;
}