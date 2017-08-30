#include <iostream>

using namespace std;


int gcd(int k, int l) {
    return l ? gcd(l, k % l) : k;
}

int lcm(int k, int l) {
    return k / gcd(k, l) * l;
}

int main() {
    string s, t;

    cin >> s >> t;
    string temp;

    int lcmSize = lcm(s.size(), t.size());
    int gcdSize = gcd(s.size(), t.size());

    string tempS = s;
    while (s.size() <= lcmSize) {
        s.append(tempS);
    }
    string tempT = t;
    while (t.size() <= lcmSize) {
        t.append(tempT);
    }

    string tempString;
    if (s.size() > t.size()) {
        tempString = s;
        s = t;
        t = tempString;
    }

    int index = 0;
    while (s.size() != t.size()) {
        s += s[index];
        index ++;
    }


    if(s == t){
        cout << 1 << endl;
    } else{
        cout << 0 << endl;
    }


    return 0;
}
