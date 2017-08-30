#include <iostream>
#include <cmath>

using namespace std;

int f(int n, int k){
    if(k==1) return n;
    return 1+f(n/2-2,k-1);
}

int main() {
    int n, k;
    cin >> n >> k;
    if(k==1){
        cout << n;
        return 0;
    }

    cout << f(n,k);

    return 0;
}//이것도 모르겟다..