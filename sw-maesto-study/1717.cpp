//
// Created by 성준영 on 2017. 9. 29..
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;


int find(vector<int> &C, int x) {
    return (C[x] == x) ? x : C[x] = find(C, C[x]);
}

void merge(vector<int> &C, int x, int y) {
    C[find(C, x)] = find(C, y);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> C(n + 1);
    for (int i = 0; i <= n; i++)
        C[i] = i;

    while ((m--) != 0) {
        int oper, a, b;
        scanf("%d %d %d", &oper, &a, &b);

        if (oper == 0) {
            merge(C, a, b);
            merge(C, a, b);
        } else {
            int aGroup;
            int bGroup;

            int aTemp = C[a];
            int bTemp = C[b];

            while(C[aTemp] != aTemp){
                aTemp = C[aTemp];
            }

            while(C[bTemp] != bTemp){
                bTemp = C[bTemp];
            }

            if (aTemp == bTemp) printf("YES\n");
            else printf("NO\n");
        }
    }
}