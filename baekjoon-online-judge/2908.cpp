#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    string r_a = "";
    string r_b = "";

    for (int i = (int) (a.length() - 1); i >= 0; i--) {
        r_a += a[i];
    }

    for (int i = (int) (b.length() - 1); i >= 0; i--) {
        r_b += b[i];
    }

    if(atoi(r_a.c_str()) > atoi(r_b.c_str())){
        cout << r_a << '\n';
    } else {
        cout << r_b << '\n';
    }

}