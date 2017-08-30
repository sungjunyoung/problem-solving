
#include <iostream>

using namespace std;

int d(int a, int b) {
    if (a == 0) {
        return b;
    }
    if(b == 1){
        return 1;
    }

    int res = 0;
    for (int i = 1; i <= b; i++) {
        res += d(a - 1, i);
    }
    return res;
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        int k, n;
        cin >> k >> n;

        cout << d(k, n) << endl;
    }
}