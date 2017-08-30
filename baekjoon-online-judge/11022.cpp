//
// Created by 성준영 on 2017. 8. 30..
//


#include <iostream>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    int index = 0;
    while (t--) {
        index++;
        int a, b;
        scanf("%d %d", &a, &b);
        int res = a + b;

        printf("Case #%d: %d + %d = %d\n", index, a, b, res);
    }
}