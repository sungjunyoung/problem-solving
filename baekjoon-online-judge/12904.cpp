#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


string change(string S) {
    reverse(S.begin(), S.end());
    return S;
}

bool flag = false;

int go(string &S, string &T) {
    int tLen = T.length();
    int sLen = S.length();
    if (flag == true) {
        return 0;
    }
    if (S == T) {
        flag = true;
        return 0;
    }
    if (sLen == tLen) {
        return 0;
    }


    if (T.find(S) < tLen || T.find(change(S)) < tLen) {
        go(change(S) += 'B', T);
        go(S += 'A', T);
    } else {
        return 0;
    }

}


int main() {
    string S, T;
    cin >> S >> T;

    go(S, T);

    if (flag == true) {
        cout << "1" << endl;
    }
    else {
        cout << "0" << endl;
    }
    return 0;
}