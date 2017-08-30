#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int x, y;

bool go(int a, int b, int k) {



    if (a == x && b == y) {
        return true;
    }

    return go((int) (a + pow(3, k)), b, k + 1) ||
           go(a, (int) (b + pow(3, k)), k + 1) ||
           go((int) (a - pow(3, k)), b, k + 1) ||
           go(a, (int) (b - pow(3, k)), k + 1);


}


int main() {
    cin >> x >> y;

    if (go(0, 0, 0)) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}