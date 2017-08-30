#include <iostream>

using namespace std;

int main() {
    string n;
    cin >> n;

    int nums[10];
    for (int i = 0; i < 10; i++) {
        nums[i] = 0;
    }

    for (int i = 0; i < n.length(); i++) {
        nums[n[i] - '0']++;
    }


    nums[6] += nums[9];
    nums[9] = 0;

    if (nums[6] % 2 == 0)
        nums[6] /= 2;
    else {
        nums[6] /= 2;
        nums[6] += 1;
    }


    int result = 0;
    for (int i = 0; i < 10; i++) {
        if (result < nums[i]) {
            result = nums[i];
        }
    }

    cout << result << endl;
}