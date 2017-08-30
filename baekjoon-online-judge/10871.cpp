//
// Created by 성준영 on 2017. 4. 12..
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int list[10001];

    for (int i = 1; i <= n; i++) {
        cin >> list[i];
    }

    string result = "";
    for(int i = 1; i<= n; i++){
        if(list[i] < x){
            result += std::to_string(list[i]);
            result += ' ';
        }
    }

    cout << result << endl;
}