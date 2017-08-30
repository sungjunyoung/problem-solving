#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> candy;
    candy.push_back(0);
    for (int i = 1, temp; i <= n; i++) {
        cin >> temp;
        candy.push_back(temp);
    }

    sort(candy.begin(), candy.end());

    vector<pair <int, int> > candyPair;
    for (int i = 0; i <= n; i++) {
        pair<int, int> p;
        p.first = i;
        p.second = 0;
        candyPair.push_back(p);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (candy[i] == candyPair[j].first) {
                candyPair[j].second++;
            }
        }
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int temp = 1;
        for (int j = 1; j <= i; j++) {
            temp *= candyPair[j].second;
        }

        ans += temp;
    }


    cout << ans - 1;

    return 0;
}