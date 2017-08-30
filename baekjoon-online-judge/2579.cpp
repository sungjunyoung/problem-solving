#include <iostream>
using namespace std;


int a[301];
int d[301][3];

int main(){
    int n;
    cin >> n;
    for ( int i=1; i<=n ; i++){
        cin >> a[i];
    }

    d[1][1] = d[1][2] = a[1];
    for(int i=2; i<=n ; i++){
        d[i][1] = d[i-2][2] + a[i];
        d[i][2] = max(d[i-1][1],d[i-2][2])+a[i];
    }

    cout << max(d[n][1],d[n][2]) << endl;
}