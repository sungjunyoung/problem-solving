#include <iostream>
#include <vector>

using namespace std;

void recursive(int n, char **a, int x, int y) {
    if (n == 3) {
        a[x][y + 2] = '*';
        a[x + 1][y + 1] = '*';
        a[x + 1][y + 3] = '*';
        a[x + 2][y] = '*';
        a[x + 2][y + 1] = '*';
        a[x + 2][y + 2] = '*';
        a[x + 2][y + 3] = '*';
        a[x + 2][y + 4] = '*';
        return;
    }

    else {
        recursive(n/2, a, x, y+(2*n)/4);
        recursive(n/2, a, x+n/2, y);
        recursive(n/2, a, x+n/2, y+(2*n)/2);
        return;
    }
}

int main() {
    int n;
    int i, j;
    cin >> n;

    char **a;
    a = new char *[n];
    for (i = 0; i < n; i++) {
        a[i] = new char[2 * n - 1];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < 2 * n - 1; j++) {
            a[i][j] = ' ';
        }
    }

    recursive(n, a, 0, 0);

    for (i = 0; i < n; i++) {
        for (j = 0; j < 2 * n - 1; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}