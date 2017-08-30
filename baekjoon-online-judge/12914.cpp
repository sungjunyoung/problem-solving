#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int checkSit(int gom) {

}

int main() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> sitRange(n + 1);

    int gom;
    cin >> gom;
    sitRange[1].first = gom;
    sitRange[1].second = gom + d;
    for (int i = 2; i <= n; i++) {
        cin >> gom;
        sitRange[i].first = gom;
        sitRange[i].second = gom + d;



        int j = 2;


    }


}