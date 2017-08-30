#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


int main() {
    int t;
    cin >> t;


    while (t--) {
        int n;
        cin >> n;

        vector<long long> q;
        q.push_back(1);

        vector<long long> two;
        vector<long long> three;
        vector<long long> result;

        int counter = 1;
        result.push_back(1);

        while (counter != n) {
            q.push_back(2 * q[0] + 1);
            q.push_back(3 * q[0] + 1);

            two.push_back(2 * q[0] + 1);
            three.push_back(3 * q[0] + 1);


            q.erase(q.begin());
            counter++;
        }



        sort(two.begin(), two.end());
        unique(two.begin(), two.end());

        sort(three.begin(), three.end());
        unique(three.begin(), three.end());

        int i = 0, j = 0;
        while (result.size() <= n){
            if (two[i] < three[j]) {
                result.push_back(two[i]);
                i++;
            } else if (two[i] > three[j]) {
                result.push_back(three[j]);
                j++;
            } else {
                result.push_back(three[j]);
                i++;
                j++;
            }
        }

        sort(result.begin(), result.end());
        //vector<long long>::iterator pos;
        //pos = unique(result.begin(), result.end());
        //result.erase(pos, result.end());
        cout << result[n - 1];
        result.clear();
    }

    return 0;
}