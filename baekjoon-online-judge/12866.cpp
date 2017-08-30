#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int i, j;

    cin >> n;
    vector<char> xy(n + 1);
    for (i = 1; i <= n; i++) {
        char temp;
        cin >> temp;
        xy[i] = temp;
    }

    vector<int> many(4);
    for (i = 1; i <= 4; i++) {
        many[i] = 0;
    }
    for (i = 1; i <= n; i++) {
        switch (xy[i]) {
            case 'A':
                many[0] += 1;
                break;
            case 'C':
                many[1] += 1;
                break;
            case 'G':
                many[2] += 1;
                break;
            case 'T':
                many[3] += 1;
                break;
        }
    }

    long long result = 1;
    for(i=0;i<4;i++){
        result *= many[i];
        result %= 1000000007;
    }


    cout << result;
    return 0;
}