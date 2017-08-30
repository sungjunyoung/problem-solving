#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;

    int flag = 0;
    int pre_flag = 0;
    int i = 0;
    int j = -1;
    while (flag < x) {
        i++;
        j++;
        flag += i;
        pre_flag += j;
    }

    int term = flag - pre_flag;
    int counter = x - pre_flag;


    if (term % 2 == 1) {
        int r_1 = term;
        int r_2 = 1;
        for (int k = 0; k < counter; k++) {
            if (k == counter - 1) {
                cout << r_1 - k << "/" << r_2 + k << endl;
            }

        }
    } else {

        int r_1 = 1;
        int r_2 = term;
        for (int k = 0; k < counter; k++) {
            if (k == counter - 1) {
                cout << r_1 + k << "/" << r_2 - k << endl;
            }

        }
    }


}