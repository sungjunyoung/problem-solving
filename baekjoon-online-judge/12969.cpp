#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;

    string s;
    for (int i = 0; i < n; i++) {
        s += 'C';
    }

    int result = 0;

    if (k == 0) {
        cout << s << endl;
        return 0;
    }

    int j = 0;
    while (j < n / 3) {
        for (int i = n - (j + 2); i >= j; i--) {
            if (s[i] == 'C') {
                s[i + 1] = 'C';
                s[i] = 'A';
                result++;
                if (result == k) {
                    cout << s << endl;
                    return 0;
                }

            } else {
                break;
            }

        }
        j++;
    }

    string newS = s.substr(n/3 , s.size()-1);
    int newN = newS.size();
    j=0;
    while (j < newN / 2) {
        for (int i = newN - (j + 2); i >= j; i--) {
            if (newS[i] == 'C') {
                newS[i + 1] = 'C';
                newS[i] = 'B';
                result++;
                if (result == k) {
                    cout << s.substr(0,n/3)+newS << endl;
                    return 0;
                }

            } else {
                break;
            }

        }
        j++;
    }


    cout << -1 << endl;
    return 0;
}