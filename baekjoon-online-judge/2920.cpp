#include <iostream>

using namespace std;

int main() {
    int list[9];
    for (int i = 1; i <= 8; i++) {
        cin >> list[i];
    }

    bool asc = true;
    bool dec = true;

    for (int i = 1; i <= 8; i++) {
        if (list[i] != i) {
            asc = false;
        }
    }

    for (int i = 1; i <= 8; i++) {
        if (list[9 - i] != i) {
            dec = false;
        }
    }

    if (!asc && !dec) {
        cout << "mixed" << '\n';
    } else if (asc){
        cout << "ascending" << '\n';
    } else if (dec) {
        cout << "descending" << '\n';
    }
}
