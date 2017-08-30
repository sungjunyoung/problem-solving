#include <iostream>
#include <cstring>

using namespace std;

int memo[101][101][101];

int go(int r, int g, int b, int count) {
    if (r < 0 || g < 0 || b < 0) {
        return 0;
    }

    int &ans = memo[r][g][b];

    if (r == 0 && g == 0 && b == 0) {
        if(ans == -1 || count < ans)
            ans = count;
        return ans;
    }

    if (ans > 0 ) {
        return ans;
    }

    ans = count;

    go(r - 1, g - 1, b - 1, count + 1);

    go(r - 3, g, b, count + 1);
    go(r, g - 3, b, count + 1);
    go(r, g, b - 3, count + 1);

    go(r, g, b - 2, count + 1);
    go(r, g - 2, b, count + 1);
    go(r - 2, g, b, count + 1);

    go(r - 1, g - 1, b, count + 1);
    go(r, g - 1, b - 1, count + 1);
    go(r - 1, g, b - 1, count + 1);

    go(r, g, b - 1, count + 1);
    go(r, g - 1, b, count + 1);
    go(r - 1, g, b, count + 1);



    return memo[0][0][0];
}

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    memset(memo, -1, sizeof(memo));


    cout << go(r,g,b,0) << endl;

    return 0;
}