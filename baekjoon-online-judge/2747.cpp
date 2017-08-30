//
// Created by 성준영 on 2017. 5. 15..
//

#include <iostream>

using namespace std;


int main() {
    int a;
    cin >> a;

    int memo[45];
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;

    for(int i=3; i<=a ; i++){
        memo[i] = memo[i-1] + memo[i-2];
    }

    cout << memo[a];
}