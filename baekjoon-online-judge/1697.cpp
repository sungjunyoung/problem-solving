#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    queue<pair<int, int> > q;
    bool visit[1000001] = {false};
    q.push(make_pair(n, 0));

    while (!q.empty()) {

        int now = q.front().first;
        int depth = q.front().second;
        q.pop();

        if(now > 100000 || now < 0) continue;
        if (visit[now]) continue;
        visit[now] = true;

        if (now == k) {
            cout << depth << endl;
            return 0;
        }

        q.push(make_pair(now * 2, depth + 1));
        q.push(make_pair(now + 1, depth + 1));
        q.push(make_pair(now - 1, depth + 1));

    }
}