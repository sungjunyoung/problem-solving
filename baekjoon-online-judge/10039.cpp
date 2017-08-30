#include <iostream>

using namespace std;

int main() {
    int list[6];

    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        cin >> list[i];
        if(list[i] < 40){
            list[i] = 40;
        }
        sum += list[i];
    }

    cout << sum/5 << endl;


}