//
// Created by 성준영 on 2017. 4. 27..
//

#include <iostream>

using namespace std;

//int main() {
//    int n;
//    cin >> n;
//
//    int a[1001] = {0};
//
//    for (int i = 1; i <= n; i++) {
//        cin >> a[i];
//    }
//
//    for (int i = 1; i <= n - 1; i++) {
//        for (int j = i + 1; j <= n; j++) {
//            if (a[i] > a[j]) {
//                int temp = a[i];
//                a[i] = a[j];
//                a[j] = temp;
//            }
//        }
//    }
//
//    for (int i = 1; i <= n; i++) {
//        cout << a[i] << endl;
//    }
//}
// 버븗정렬

int main() {
    int n;
    cin >> n;

    int a[1001] = {0};

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int b[1001] = {0};

    for (int i = 1; i <= n; i++) {
        int minIndex = i;
        for (int j = i; j <= n; j++) {
            if(a[minIndex] > a[j]){
                minIndex = j;
            }
        }
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }

    for(int i=1;i<=n;i++){
        cout << a[i] << endl;
    }
}
// 선택정렬