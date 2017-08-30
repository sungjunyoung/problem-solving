#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int p1, p2, p3, x1, x2, x3;
    cin >> p1 >> p2 >> p3 >> x1 >> x2 >> x3;
    vector<pair<int,int>> sortedVector(3);
    sortedVector[0].first = p1;
    sortedVector[0].second = x1;
    sortedVector[1].first = p2;
    sortedVector[1].second = x2;
    sortedVector[2].first = p3;
    sortedVector[2].second = x3;

    sort(sortedVector.begin(), sortedVector.end());

    long long n = 0;
    int i = 0;

    if (p1 == p2 && p2 == p3) {
        cout << -1 << endl;
        return 0;
    }
    if (x1 == x2 && x2 == x3) {
        cout << x1 << endl;
        return 0;
    }



    while (n < 1000000000) {
        n = sortedVector[2].second + sortedVector[2].first * i;
        i++;
        if (n % sortedVector[1].first == sortedVector[1].second && n % sortedVector[0].first == sortedVector[0].second) {
            cout << n << endl;
            return 0;
        }
    }


    cout << -1 << endl;

    return 0;
}