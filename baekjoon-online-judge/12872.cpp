#include <iostream>
#include <cstring>

using namespace std;

int n, m, p;
long long d[101][101][101];

long long go(int position, int x, int y) {

    if (position == p) {
        if (y == 0)
            return 1;
        return 0;
    }

    long long &ans = d[position][x][y];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    if (y > 0) {
        ans += go(position + 1, x + 1, y - 1) * y;
    }
    if (x > m) {
        ans += go(position + 1, x, y) * (x - m);
    }
    ans %= 1000000007;
    return ans;
}

int main() {
    cin >> n >> m >> p;
    memset(d, -1, sizeof(d));

    cout << go(0, 0, n) << endl;

    return 0;
}