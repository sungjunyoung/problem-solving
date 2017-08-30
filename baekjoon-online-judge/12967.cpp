#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[2001] = {0,};

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> secondA;
    for (int i = 1; i <= n; i++) {
        if (k % a[i] == 0 || a[i] % k == 0) {
            secondA.push_back(a[i]);
        }
    }


    int count = 0;
    for (int i = 0; i < secondA.size() - 2; i++) {
        for (int j = i + 1; j < secondA.size() - 1; j++) {
            for (int l = j + 1; l < secondA.size(); l++) {
                if (secondA[i] % k == 0 || secondA[j] % k == 0 || secondA[l] % k == 0) {
                    count++;
                } else if((secondA[i] * secondA[j] * secondA[l]) % k == 0){
                    count ++;
                }
            }
        }

    }

    cout << count << endl;

    return 0;
}