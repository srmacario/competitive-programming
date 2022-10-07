#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const int T = 1 << 10;

int t, p, e[T], d[N], s[N], dp[T][N][N];
bool vis[T][N][N];

int calc(int x = (1 << t) - 1, int y = 0, int z = 0){
    if(z == p)
        return 0;
    if(vis[x][y][z])
        return dp[x][y][z];
    vis[x][y][z] = true;
    dp[x][y][z] = calc(x, y, z + 1);
    if(x)
        for(int j = 0; j < t; j++)
            if(x & (1 << j))
                dp[x][y][z] = max(dp[x][y][z], calc(x ^ (1 << j), e[j], z));
    if(y >= d[z])
        dp[x][y][z] = max(dp[x][y][z], s[z] + calc(x, y - d[z], z + 1));
    return dp[x][y][z];
}

int main(){
    scanf("%d %d", &t, &p);
    for(int i = 0; i < t; i++)
        scanf("%d", &e[i]);
    for(int i = 0; i < p; i++)
        scanf("%d", &d[i]);
    for(int i = 0; i < p; i++)
        scanf("%d", &s[i]);
    printf("%d\n", calc());
    return 0;
}