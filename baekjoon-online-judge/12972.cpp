#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0, x; i < n * n; i++) {
        cin >> x;
        arr.push_back(x);
    }

    vector<int> resultArr;
    while (resultArr.size() != n) {
        if (resultArr.size() > 2) {
            for (int i = 0; i < resultArr.size() - 1; i++) {
                int gcd = __gcd(resultArr[i], resultArr.back());

                for (int j = 0; j < 2; j++) {
                    arr.erase(find(arr.begin(), arr.end(), gcd));
                }
            }
        }


        vector<int>::iterator max = max_element(arr.begin(), arr.end());
        int mymax = *max;
        resultArr.push_back(mymax);
        arr.erase(max);

    }

    for (int i = 0; i < resultArr.size(); i++) {
        cout << resultArr[i] << " ";
    }

    return 0;
}