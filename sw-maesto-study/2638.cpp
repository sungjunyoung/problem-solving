//
// Created by 성준영 on 2017. 9. 29..
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int i_to[] = {-1, 0, 1, 0};
int j_to[] = {0, 1, 0, -1};

int n, m;
int next_i = 0, next_j = 0;

int checker(vector<vector<int> > &ground, int ii, int jj) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        int curI = ii + i_to[i];
        int curJ = jj + j_to[i];

        if (curI < 0 || curI >= n) {
            continue;
        } else if (curJ < 0 || curJ >= m) {
            count ++;
        } else {
            if (ground[curI][curJ] == -1) {
                count++;
            }
        }
    }
    return count;
}

void initExternal(vector<vector<int> > &ground, int ii, int jj) {
    queue<pair<int, int> > q;
    q.push(make_pair(ii, jj));

    while (!q.empty()) {
        int qi = q.front().first;
        int qj = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int curI = qi + i_to[i];
            int curJ = qj + j_to[i];

            if (curI < 0 || curJ < 0 || curI >= n || curJ >= m) {
                continue;
            } else {
                if (ground[curI][curJ] == 0) {
                    ground[curI][curJ] = -1;
                    q.push(make_pair(curI, curJ));
                }
            }
        }
    }
}

vector<vector<int> > melt(vector<vector<int> > &origGround) {
    initExternal(origGround, 0, 0);
    vector<vector<int> > nextGround = origGround;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (checker(origGround, i, j) >= 2) {
                nextGround[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (nextGround[i][j] == -1) {
                nextGround[i][j] = 0;
            }
        }
    }

    return nextGround;
}

bool isAllMelt(vector<vector<int> > &ground) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ground[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;

    vector<vector<int> > ground(n);
    for (int i = 0; i < n; i++) {
        ground[i].resize(m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            scanf("%d", &temp);
            ground[i][j] = temp;
        }
    }

    int result = 0;

    while (!isAllMelt(ground)) {
        ground = melt(ground);

        /* */
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                printf("%d ", ground[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
        /* */

        result++;
    }
    cout << result << endl;
}