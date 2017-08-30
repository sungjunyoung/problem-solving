//
// Created by 성준영 on 2017. 5. 15..
//

#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>

using namespace std;

vector<int> rel[100001];
int parent[100001];

void DFS(int cur) {
    for (int i: rel[cur]) {
        if (parent[i] == -1) {
            parent[i] = cur;
            DFS(i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=1;i<n;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        rel[a].push_back(b);
        rel[b].push_back(a);
    }

    memset(parent, -1, sizeof(parent));

    DFS(1);
    for (int i = 2; i <= n; i++) {
        printf("%d\n", parent[i]);
    }
}