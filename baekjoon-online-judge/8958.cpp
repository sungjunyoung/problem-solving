//
// Created by 성준영 on 2017. 4. 12..
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string OX;
        cin >> OX;

        int sum = 0;
        for (int i = 0; i < OX.length(); i++) {

            int count = 0;
            for (int j = 0; j <= i; j++) {
                if (OX[j] == 'O') {
                    count++;
                } else {
                    count = 0;
                    continue;
                }
            }

            sum += count;
        }

        cout << sum << endl;
    }
}