#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;

const int N = 45;
const int M = 405;

int dp[10][M][N][N], a[N][M], n, m, c[10][N][M];
bool vis[10][M][N][N];

int cst(int l, int r, int x, int d){ return c[x][r + 1][d] - c[x][l][d]; }

int calc(int x, int d, int l, int r){
    if(l > r || d > m)
        return 0;
    if(x > 9)
        return N * M;
    if(vis[x][d][l][r])
        return dp[x][d][l][r];
    vis[x][d][l][r] = true;
    dp[x][d][l][r] = M * N;
    for(int i = l; i <= r; i++)
        for(int j = x; j < 10; j++)
            dp[x][d][l][r] = min(dp[x][d][l][r], cst(l, i, j, d) + 
            calc(j + 1, d, i + 1, r) + calc(0, d + 1, l, i));
    return dp[x][d][l][r];
}

void rec(int x, int d, int l, int r){
    if(l > r || d > m)
        return;
    for(int i = l; i <= r; i++)
        for(int j = x; j < 10; j++)
            if(cst(l, i, j, d) + calc(j + 1, d, i + 1, r) + calc(0, d + 1, l, i) == dp[x][d][l][r]){
                for(int ii = l; ii <= i; ii++)
                    a[ii][d] = j;
                rec(j + 1, d, i + 1, r);
                rec(0, d + 1, l, i);
                return;
            }
}

int main(){
    scanf("%d %d", &n, &m);
    char cc;
    for(int i = 0; i < 10; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 0; k < m; k++)
                c[i][j][k] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            scanf(" %c", &cc);
            a[i][j] = (cc - '0');
            c[a[i][j]][i + 1][j] = 0;
        }
    for(int i = 0; i < 10; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 0; k < m; k++)
                c[i][j][k] += c[i][j - 1][k];
    calc(0, 0, 0, n - 1);
    rec(0, 0, 0, n - 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            printf("%d", a[i][j]);
        printf("\n");
    }
    return 0;
}