//
// Created by 성준영 on 2017. 4. 10..
//

#include <iostream>
#include <string>

using namespace std;

//int main() {
//    int N, sum = 0;
//    string num;
//    cin >> N >> num;
//    for (int i = 0; i < N; i++){
//        sum += num.at(i) - '0';
//    }
//
//
//    cout << sum;
//    return 0;
//}
//

int main() {
    int t;
    scanf("%d", &t);

    int result = 0;
    while (t--) {
        int input;
        scanf("%1d", &input);
        result += input;
    }

    cout << result << endl;
}