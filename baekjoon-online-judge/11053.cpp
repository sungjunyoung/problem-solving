#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n + 1);
    vector<int> D(n + 1);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= n; i++) {
        D[i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {

            if (arr[i] > arr[j] && D[j] + 1 > D[i]) {
                D[i] = D[j] + 1;
            }

        }
    }

    int max = D[1];
    for (int i = 2; i <= n; i++) {
        if(max < D[i]){
            max = D[i];
        }
    }

    cout << max << endl;
}