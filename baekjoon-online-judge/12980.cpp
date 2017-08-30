#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int arr[101] = {0,};
    vector<int> permutation;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        arr[i] = x;
    }

    for (int i = 1; i <= n; i++) {
        permutation.push_back(i);
    }

    vector<int> noneIntVec;
    vector<int> noneIndexVec;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (permutation[j] == arr[i]) {
                permutation[j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (permutation[i] != 0) {
            noneIntVec.push_back(permutation[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0) {
            noneIndexVec.push_back(i);
        }
    }


    int resultCount = 0;
    do {
        for (int i = 0; i < noneIntVec.size(); i++) {
            arr[noneIndexVec[i]] = noneIntVec[i];
        }

        int count = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i; j <= n; j++) {
                if (arr[i] < arr[j]) {
                    count++;
                }
            }
        }
        if (count == s){
            resultCount ++;
        }

    } while (next_permutation(noneIntVec.begin(), noneIntVec.end()));


    cout << resultCount << endl;
    return 0;
}