//
// Created by 성준영 on 2017. 4. 10..
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;

    while(n > 0){
        if(n%5 == 0){
            count += n/5;
            break;
        } else {
            n -= 3;
            count ++;
        }
    }

    if(n<0){
        cout << -1;
        return 0;
    }
    cout << count;
    return 0;
}