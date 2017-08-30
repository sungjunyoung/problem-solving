#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


bool go(string t, string s) {
    if (t == s) {
        return true;
    }
    if (t.length() == s.length() && t != s) {
        return false;
    }


    if (t.front() == 'A' && t.back() == 'A') {
        t = t.substr(0, t.length() - 1);
        return go(t, s);
    } else if (t.front() == 'B' && t.back() == 'B') {
        t = t.substr(1, t.length() );
        reverse(t.begin(), t.end());
        return go(t, s);
    } else if (t.front() == 'A' && t.back() == 'B') {
        return 0;
    } else {
        string a, b;
        a = t.substr(0, t.length() - 1);
        b = t.substr(1, t.length() );
        reverse(b.begin(), b.end());

        return go(a, s) || go(b, s);
    }
}

int main() {
    string s, t;
    cin >> s >> t;

    cout << go(t, s) << endl;

    return 0;
}