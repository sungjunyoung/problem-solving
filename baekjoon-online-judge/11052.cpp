#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> P(n + 1);
    vector<int> D(n + 1);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &P[i]);
    }

    D[1] = P[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            D[i] = max(D[i], P[j] + D[i-j]);
        }
    }

    cout << D[n] << endl;
}