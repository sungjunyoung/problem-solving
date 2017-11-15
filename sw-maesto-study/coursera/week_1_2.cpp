//
// Created by 성준영 on 2017. 10. 10..
//

#include <iostream>
#include <string>
#
 <vector>

using namespace std;

int to_root(vector<int> &parents, vector<int> &cache, int node_id) {
    int parent = parents[node_id];
    if (parent == -1) {
        return 1;
    }

    if (cache[node_id] != 0) {
        return cache[node_id];
    }

    cache[node_id] = 1 + to_root(parents, cache, parents[node_id]);
    return cache[node_id];

}

int main() {
    int n;
    cin >> n;
    vector<int> parents(n);
    vector<int> cache(n);

    for (int i = 0; i < n; i++) {
        cin >> parents[i];
    }

    for (int i = 0; i < n; i++) {
        to_root(parents, cache, i);
    }

    int result = cache[0];
    for (int i = 0; i < n; i++) {
        if(cache[i] > result){
            result = cache[i];
        }
    }
    cout << result << endl;

    return 0;
}