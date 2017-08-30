#include <iostream>

using namespace std;

const int inf = 100000000;

int main() {
    int n, m;
    cin >> n >> m;
    int table[1001][1001];
    int dist[1001];
    int check[1001];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            table[i][j] = inf;
        }
    }

    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (table[x][y] > z) {
            table[x][y] = z;
        }
    }

    int start, end;
    cin >> start >> end;
    for (int i = 1; i <= n; i++) {
        dist[i] = inf;
    }

    dist[start] = 0;
    check[start] = true;
    for (int i = 1; i <= n; i++) {
        dist[i] = table[start][i];
    }

    int pin;
    for(int k=1;k<=n;k++){
        int min = inf+1;
        for (int i = 1; i <= n; i++) {
            if(check[i] == false){
                if(min > dist[i]){
                    min = dist[i];
                    pin = i;
                }
            }
        }

        check[pin] = true;

        for(int i=1;i<=n;i++){
            if(dist[i] > dist[pin] + table[pin][i]){
                dist[i] = dist[pin] + table[pin][i];
            }
        }

    }

    cout << dist[end] << endl;

    return 0;
}