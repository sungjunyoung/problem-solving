//
// Created by 성준영 on 2017. 4. 12..
//

#include <iostream>

using namespace std;

bool isHansu(int x) {
    if (x / 100 == 0) {
        return true;
    } else {

        int list[5] = {-1,-1,-1,-1,-1};
        int count = 0;
        while (x != 0) {
            count++;
            list[count] = x % 10;
            x = x / 10;
        }

        int subCount = 0;
        for (int i = 1; i <= 4; i++) {
            if (list[i] != -1) {
                subCount++;
            }
        }

        int gap = list[1] - list[2];
        for (int i = 2; i <= subCount - 1; i++) {
            if(list[i]- list[i+1] != gap){
                return false;
            } else{
                continue;
            }
        }

        return true;
    }
}

int main() {
    int n;

    cin >> n;

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (isHansu(i)) {
            count++;
        } else {
            continue;
        }
    }

    cout << count ;

}