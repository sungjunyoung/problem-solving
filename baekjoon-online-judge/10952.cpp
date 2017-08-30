//
// Created by 성준영 on 2017. 8. 30..
//


#include <iostream>
using namespace std;

int main(){
    while(1){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a == 0 && b == 0){
            break;
        }

        printf("%d\n", a+b);
    }
}