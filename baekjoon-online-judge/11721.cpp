//
// Created by 성준영 on 2017. 4. 10..
//

#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;
//
//int main() {
//    char word[101];
//    scanf("%s", word);
//
//    int count = 0;
//    int totalCount = 0;
//    string tempWord;
//    while (totalCount < strlen(word)) {
//
//        tempWord += word[totalCount];
//
//        totalCount++;
//        count++;
//
//        if(count == 10){
//            cout << tempWord << endl;
//            tempWord = "";
//            count = 0;
//        }
//
//    }
//    cout << tempWord << endl;
//}

int main() {
    char a[100];
    while (scanf("%10s", a) == 1){
        printf("%s\n",a);
    }
    return 0;
}