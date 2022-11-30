#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

const int INF = 0x3f3f3f3f;

int t, r, c;
vector<vector<char>> grid;
vector<vector<vector<pair<int, int>>>> adj;
vector<vector<int>> dist;
pair<int, int> s, e;

string str;

bool check(int i, int j) {
    if (i < 0 or i >= r) return false;
    if (j < 0 or j >= c) return false;
    return true;
}

int bfs() {
    dist[s.x][s.y] = 1;
    queue<pair<int, int>> q;
    q.push(s);

    while (q.size()) {
        pair<int, int> u = q.front();
        q.pop();

        for (pair<int, int> v : adj[u.x][u.y]) {
            if (dist[v.x][v.y] == INF) {
                dist[v.x][v.y] = dist[u.x][u.y] + 1;
                q.push(v);
            }
        }
    }

    return dist[e.x][e.y];
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> r >> c;
        grid.assign((4 * r + 3), vector<char>(6 * c + 3));
        getline(cin, str);
        for (int i = 0; i < 4 * r + 3; i++) {
            getline(cin, str);
            for (int j = 0; j < 6 * c + 3; j++) grid[i][j] = str[j];
        }

        dist.assign(r, vector<int>(c, INF));
        adj.assign(r, vector<vector<pair<int, int>>>(c, vector<pair<int, int>>()));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int col = 4 + 6 * j;
                int lin = 2 + 4 * i;
                int a = 0;

                if (j & 1) lin += 2;
                else a--;

                if (grid[lin][col] == 'S') s = { i, j };
                if (grid[lin][col] == 'T') e = { i, j };

                if (grid[lin-1][col-3] != '/') {
                    int ni = i + a;
                    int nj = j - 1;

                    if (check(ni, nj)) adj[i][j].push_back({ ni, nj });
                }

                if (grid[lin+1][col-3] != '\\') {
                    int ni = i + 1 + a;
                    int nj = j - 1;

                    if (check(ni, nj)) adj[i][j].push_back({ ni, nj });
                }

                if (grid[lin-1][col+3] != '\\') {
                    int ni = i + a;
                    int nj = j + 1;

                    if (check(ni, nj)) adj[i][j].push_back({ ni, nj });
                }

                if (grid[lin+1][col+3] != '/') {
                    int ni = i + 1 + a;
                    int nj = j + 1;

                    if (check(ni, nj)) adj[i][j].push_back({ ni, nj });
                }

                if (grid[lin-2][col] != '-') {
                    int ni = i - 1;
                    int nj = j;

                    if (check(ni, nj)) adj[i][j].push_back({ ni, nj });
                }

                if (grid[lin+2][col] != '-') {
                    int ni = i + 1;
                    int nj = j;

                    if (check(ni, nj)) adj[i][j].push_back({ ni, nj });
                }
            }
        }

        //for (int i = 0; i < r; i++) {
        //    for (int j = 0; j < c; j++) {
        //        cout << "(i, j) " << i << " " << j << "\n";
        //        for (auto [ u, v ] : adj[i][j]) cout << u << ", " << v << "\n";
        //    }
        //}

        int val = bfs();
        if (val == INF) val = -1;
        cout << val << "\n";
    }
}