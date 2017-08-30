//
// Created by 성준영 on 2017. 5. 16..
//

#include <iostream>
using namespace std;

long long int memo[1001][1001] = {-1,};

long long int rcsv(int n, int k){
    if(memo[n][k] > 0){
        return memo[n][k];
    }

    if (n == k || k == 0){
        memo[n][k] = 1;
        return 1;
    }

    return memo[n][k] = (rcsv(n-1, k-1) + rcsv(n-1,k)) % 10007;
}

int main(){
    int n, k;
    cin >> n >> k;

    cout << rcsv(n,k)<< endl;
}