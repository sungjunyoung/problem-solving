#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<int> > &graph, int start, vector<bool> &d_visit) {
    if (d_visit[start]) return;
    printf("%d ", start);
    d_visit[start] = true;
    for (int i = 1; i <= graph.size(); i++) {
        if (!d_visit[i] && graph[start][i] == 1) {
            dfs(graph, i, d_visit);
        }
    }
}

void bfs(vector<vector<int> > &graph, int start, vector<bool> &b_visit) {
    queue<int> q;
    q.push(start);
    b_visit[start] = true;
    printf("%d ", start);
    while (!q.empty()) {
        int now = q.front();
        for (int i = 1; i <= graph.size(); i++) {
            if (!b_visit[i] && graph[now][i] == 1) {
                q.push(i);
                b_visit[i] = true;
                printf("%d ", i);
            }
        }
        q.pop();
    }
}

int main() {
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);

    vector<vector<int> > graph(n + 1);
    for (int i = 1; i <= n; i++) {
        graph[i].resize(n + 1);
    }

    for (int i = 1; i <= m; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        graph[node1][node2] = 1;
        graph[node2][node1] = 1;
    }

    vector<bool> d_visit(n + 1);
    vector<bool> b_visit(n + 1);

    dfs(graph, v, d_visit);
    printf("\n");
    bfs(graph, v, b_visit);
}