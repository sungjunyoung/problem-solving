#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, i, j;
    cin >> n >> m;

    vector<int> vec(n);
    int temp;
    for (i = 0; i < n; i++) {
        cin >> temp;
        vec[i] = temp;
    }

    int len = 500;
    vector<int> sqrt_500(n / len);
    int minInt = vec[0];
    for (i = 1; i < n; i++) {
        sqrt_500[i / len] = min(minInt, vec[i]);
        minInt = min(minInt, vec[i]);
    }


    int a, b;
    int resultMin, resultMax;
    for(i=1;i<=m;i++){
        cin >> a >> b;
        for(int i=1;i<=b;i++){
            min=
            if(i%len == 0 && i+len-1<=b){
                //operation for a bunch 묶음에 대한 연산을 수행해 준다

            }
            else{
                //operation for an unit

            }
        }
    }

    return 0;
}