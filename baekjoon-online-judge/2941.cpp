#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    string list[8] = {"c=", "c-", "d-", "lj", "nj", "s=", "z=", "dz="};

    int count = (int) s.length();

    for (int i = 1; i < s.length(); i++) {
        string temp = "";
        temp += s[i - 1];
        temp += s[i];

        for (int j = 0; j < 8; j++) {
            if (temp == "z=" && i != 1 && s[i - 2] == 'd') {
                continue;
            }

            if (temp == list[j]) {
                count -= 1;
            }
        }
    }

    for (int i = 2; i < s.length(); i++) {
        string temp = "";
        temp += s[i - 2];
        temp += s[i - 1];
        temp += s[i];

        for (int j = 0; j < 8; j++) {
            if (temp == list[j]) {
                count -= 2;
            }
        }
    }

    cout << count << '\n';
}