#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int result = n;
    while (n--) {
        string s;
        cin >> s;

        int list[26];
        for (int i = 0; i < 26; i++) {
            list[i] = 0;
        }

        list[s[0] - 97]++;

        for (int i = 1; i < s.length(); i++) {

            if (list[s[i] - 97] != 0 && s[i - 1] != s[i]) {
                result--;
                break;
            } else {
                list[s[i] - 97]++;
            }
        }

    }
    cout << result;
}