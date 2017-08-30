#include <iostream>

using namespace std;

int main() {
    int n,m,i,j;
    int miro[101][101];
    int input[101];
    int d[101][101];
    cin >> n >> m;
    for(i=1;i<=m;i++){
        cin >> input[i];
    }

    for(i=1; i<=m;i++){
        for(j=n;j>=1;j--){
            miro[i][j] = input[i]%10;
            input[i] = input[i]/10;
        }
    }


    d[1][1] = miro[1][1];
    for(i=2;i<=n;i++){
        d[i][1] = d[i-1][1]+miro[i][1];
    }
    for(j=2;j<=m;j++){
        d[1][j] = d[1][j-1]+miro[1][j];
    }

    for(i=2; i<=n;i++){
        for(j=2;j<=m;j++){
            d[i][j] = min(d[i][j-1]+miro[i][j],d[i-1][j]+miro[i][j]);
        }
    }

    cout << d[n][m];
    //ㅠㅠ 못풀겟다
    return 0;
}