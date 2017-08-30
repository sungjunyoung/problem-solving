//
// Created by 성준영 on 2017. 5. 16..
//

#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    int top = 1, bottom = 1;
    int tk = k;
    while(k--){
        top *= n;
        n--;
    }

    while(tk--){
        bottom *= tk+1;
    }

    cout << top / bottom << endl;
}