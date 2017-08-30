#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long d;
    cin >> n >> d;

    vector<pair<long long, long long>> p(100001);

    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }


    sort(p.begin() + 1, p.begin() + n + 1);

    vector<long long> a(100001);
    a[1] = p[1].second;
    for (int i = 2; i <= n; i++) {
        a[i] = p[i].second + a[i - 1];
    }

    int head = 1;
    int tail = 1;
    long long maxResult = 0;
    while (tail != n + 1) {

        if (p[tail].first - p[head].first < d) {
            maxResult = max(maxResult, a[tail] - a[head - 1]);
            tail++;
        } else {
            head++;
        }
    }

    cout << maxResult << endl;
    return 0;
}