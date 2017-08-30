//
// Created by 성준영 on 2017. 4. 12..
//

#include <iostream>

using namespace std;

int main() {
    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;
        int list[1001];
        for (int i = 1; i <= n; i++) {
            cin >> list[i];
        }

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += list[i];
        }
        int average = sum / n;

        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (list[i] > average) {
                count++;
            }
        }

        float result = float(count) / float(n);
        printf("%.3f", result*100);
        cout << "%" << endl;
    }
}