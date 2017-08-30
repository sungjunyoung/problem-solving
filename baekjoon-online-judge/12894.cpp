#include <iostream>
#include <string.h>

using namespace std;

bool flag = true;

int equi(string a, string b) {

    if (a.length() == 0) {
        return 0;
    }

    if (a.length() == 1 && a == b) {
        return 1;
    } else if( a.length() == 1 && a!= b){
        return 0;
    }
    if (equi(a.substr(0, a.length() / 2), b.substr(0, b.length() / 2)) == 1 &&
        equi(a.substr(a.length() / 2, a.length()), b.substr(b.length() / 2, b.length() - 1)) == 1 ||
        equi(a.substr(0, a.length() / 2), b.substr(b.length() / 2, b.length() - 1)) == 1 &&
        equi(a.substr(a.length() / 2, a.length()), b.substr(0, b.length() / 2)) == 1 ) {
        return 1;
    } else {

        return 0;
    }

}

int main() {
    string a, b;
    cin >> a >> b;

    if (a == b) {
        cout << "YES" << '\n';
        return 0;
    }

    if(equi(a, b) == 1){
        cout << "YES" << endl;
    } else{
        cout <<"NO" << endl;
    }


    return 0;
}
