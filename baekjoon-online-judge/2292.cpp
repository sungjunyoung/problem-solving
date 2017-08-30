#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if(n==1){
        cout << 1 << endl;
        return 0 ;
    }

    int counter = 2;
    int result = 0;
    while (counter <= n) {

        counter = counter + result * 6;

        result++;
    }

    cout << result << endl;
}