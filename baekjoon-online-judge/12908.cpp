#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> startPoint;
pair<int, int> endPoint;

pair<pair<int, int>, pair<int, int>> teleport[3];

int ans = 0;

int go(int xs, int ys, int ans) {
    int goX, goY;

    if (xs < 0 || ys < 0) {
        return 0;
    }

    if(xs == endPoint.first && ys == endPoint.second){
        return ans;
    }

    for (int i = 0; i < 3; i++) {
        if (xs == teleport[i].first.first && ys == teleport[i].first.second) {
            ans += 10;
            goX = teleport[i].second.first;
            goY = teleport[i].second.second;
        }//텔레포트를 타는경우
    }

    for (int i = 0; i < 4; i++) {
        ans = min(min(go(xs + 1, ys, ans + 1),
                      go(xs, ys + 1, ans + 1)),
                  min(go(xs - 1, ys, ans + 1),
                      go(xs, ys - 1, ans + 1)));
    }

    ans = min(ans, go(goX, goY, ans));
    return ans;
}


int main() {

    cin >> startPoint.first;
    cin >> startPoint.second;
    cin >> endPoint.first;
    cin >> endPoint.second;

    for (int i = 0; i < 3; i++) {
        cin >> teleport[i].first.first;
        cin >> teleport[i].first.second;
        cin >> teleport[i].second.first;
        cin >> teleport[i].first.second;
    }
    cout << go(startPoint.first,startPoint.second,0);

    return 0;
}