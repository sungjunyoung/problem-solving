#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int n, k, i, j;
    cin >> n >> k;
    int d[n+1][k+1];
    for(i=0;i<n+1;i++){
        for(j=0;j<k+1;j++){
            d[i][j] = 0;
        }
    }
    vector<int> weigth(n + 1);
    vector<int> price(n + 1);

    int tempWeight;
    int tempPrice;
    weigth[0] = 0;
    price[0] = 0;
    for (i = 1; i <= n; i++) {
        cin >> tempWeight >> tempPrice;
        weigth[i] = tempWeight;
        price[i] = tempPrice;
    }

    for (i = 0; i <= n; i++) {
        d[i][0] = 0;
    }
    for (i = 0; i <= k; i++) {
        d[0][i] = 0;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= k; j++) {
            if (weigth[i] <= j)
                d[i][j] = max(d[i - 1][j - weigth[i]] + price[i], d[i - 1][j]);
            else {
                d[i][j] = d[i - 1][j];
            }
        }
    }


    cout << d[n][k] << endl;

    return 0;
}