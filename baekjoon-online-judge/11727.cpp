#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> D(n + 1);

    D[0] = 0;
    D[1] = 1;
    D[2] = 3;

    for (int i = 3; i <= n; i++) {
        D[i] = (D[i - 1] + D[i-2] + D[i-2])%10007;
    }

    cout << D[n];
}