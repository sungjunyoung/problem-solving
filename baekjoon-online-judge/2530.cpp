#include <iostream>

using namespace std;

int main() {

    int h, m, s;
    cin >> h >> m >> s;
    int d;
    cin >> d;

    s = s + d;

    while (s >= 60) {
        s = s - 60;
        m += 1;
    }

    while (m >= 60) {
        m = m - 60;
        h += 1;
    }

    while (h >= 24) {
        h = h - 24;
    }

    cout << h << " " << m << " " << s;
    return 0;
}