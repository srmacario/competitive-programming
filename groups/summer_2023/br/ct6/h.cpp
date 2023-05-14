#include <bits/stdc++.h>

using namespace std;
int n, m, d;
const int INF = 0x3f3f3f3f;
vector<vector<int>> dist;
vector<string> board;
queue<pair<int, int>> q;
int xi, yi, xf, yf;
bool ans = true;
int caminho = 0;
void bfs(int xi, int yi){
    dist[xi][yi] = 0;
    pair<int, int> p = make_pair(xi, yi);
    q.push(p);
    while(!q.empty()) {
        pair<int, int> u = q.front();
        xi = u.first;
        yi = u.second;
        q.pop();
        if(xi+1 < n) {
            if(board[xi+1][yi] == '.' or board[xi+1][yi] == 'F') {
                if(dist[xi+1][yi] > dist[xi][yi]+1) {
                    dist[xi+1][yi] = dist[xi][yi] + 1;
                    p = make_pair(xi+1, yi);
                    q.push(p);
                }
            }
        }
        if(xi-1 >=0) {
            if(board[xi-1][yi] == '.' or board[xi-1][yi] == 'F') {
                if(dist[xi-1][yi] > dist[xi][yi]+1) {
                    dist[xi-1][yi] = dist[xi][yi] + 1;
                    p = make_pair(xi-1, yi);
                    q.push(p);
                }
            }
        }
        if(yi + 1 < m) {
            if(board[xi][yi+1] == '.' or board[xi][yi+1] == 'F') {
                if(dist[xi][yi+1] > dist[xi][yi]+1) {
                    dist[xi][yi+1] = dist[xi][yi] + 1;
                    p = make_pair(xi,yi+1);
                    q.push(p);
                }
            }
        }
        if(yi-1 >=0) {
            if(board[xi][yi-1] == '.' or board[xi][yi-1] == 'F') {
                if(dist[xi][yi-1] > dist[xi][yi]+1) {
                    dist[xi][yi-1] = dist[xi][yi] + 1;
                    p = make_pair(xi,yi-1);
                    q.push(p);
                }
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> d;
    dist.resize(n);
    board.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> board[i];
        dist[i].resize(m);
    }
    for(int i = 0; i < n; i++) {
        for(int j =0; j < m; j++) {
            dist[i][j] = INF;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'M') {
                for(int k = 1; k <=d; k++) {
                    if(i+k < n)
                        board[i+ k][j] = 'H';
                    if(i - k >= 0)
                        board[i- k][j] = 'H';
                    if(j+k < m)
                        board[i][j+k] =  'H';
                    if(j-k >=0)
                        board[i][j-k] = 'H';
                }
            }
            if(board[i][j] == 'S') {
                xi = i;
                yi = j;
            }
            if(board[i][j] == 'F') {
                xf = i;
                yf = j;
            }
            
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
    // for(int i = 0; i < n; i++) {
    //     cout << board[i] << "\n";
    // }
    if(board[xi][yi] == 'H')
        ans = false;
    bfs(xi, yi);
    if(dist[xf][yf] < INF) {
        caminho = dist[xf][yf];
    }
    else
        ans = false;
    if(!ans)
        cout << "-1\n";
    else
        cout << caminho << "\n";
    return 0;
}