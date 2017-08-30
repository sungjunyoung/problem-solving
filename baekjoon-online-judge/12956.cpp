#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int MAX = 1000000;

int main() {
    int n, m;
    cin >> n >> m;
    int table[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                table[i][j] = 0;
            } else {
                table[i][j] = MAX;
            }
        }
    }

    vector<tuple<int, int, int>> temp;
    for (int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        table[x][y] = z;
        table[y][x] = z;
        temp.push_back(make_tuple(x, y, z));
    }

    int originalFloyd[101][101];
    int originalTable[101][101];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            originalFloyd[i][j] = table[i][j];
            originalTable[i][j] = table[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (originalFloyd[i][k] + originalFloyd[k][j] < originalFloyd[i][j]) {
                    originalFloyd[i][j] = originalFloyd[i][k] + originalFloyd[k][j];
                }
            }
        }
    }


    for (int i = 0; i < temp.size(); i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                table[k][j] = originalTable[k][j];
            }
        }

        table[get<0>(temp[i])][get<1>(temp[i])] = MAX;

        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < n; l++) {
                    if (table[j][k] + table[k][l] < table[j][l]) {
                        table[j][l] = table[j][k] + table[k][l];
                    }
                }
            }
        }

        int count = 0;
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                if (originalFloyd[k][j] < table[k][j]) {
                    count++;
                }
            }
        }
        cout << count << " ";
    }


    return 0;
}