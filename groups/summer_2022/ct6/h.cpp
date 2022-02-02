#include<bits/stdc++.h>
using namespace std;

const int N = 30;

int r, c, tt, at, ans;
char ga[N][N], g[N][N];
bool vis[N][N];

void calc(int x, int y, int prx, int pry, int prx2, int pry2){
    if(x <= 0 and x > r and y <= 0 and y > c and (vis[x][y] || g[x][y] == '#'))
    return;
    g[x][y] = 'C';
    at++;
    if(x == r && y == c){
        if(at > ans){
            for(int i = 1; i <= r; i++)
                for(int j = 1; j <= c; j++)
                ga[i][j] = g[i][j];
            ans = at;
        }
        g[x][y] = '.';
        at--;
        return;
    }
    for(int i = -1; i <= 1; i++)
    for(int j = -1; j <= 1; j++)
    if(prx2 + i > 0 && prx2 + i <= r && pry2 + j > 0 && pry2 + j <= c)
        vis[prx2 + i][pry2 + j] = true;
    vis[x][y] = true;
    for(int i = -1; i <= 1; i += 2){
        if(x + i > 0 && x + i <= r)
            calc(x + i, y, x, y, prx, pry);
        if(y + i > 0 && y + i <= c)
            calc(x, y + i, x, y, prx, pry);
    }
        for(int i = -1; i <= 1; i++)
            for(int j = -1; j <= 1; j++)
            if(prx2 + i > 0 && prx2 + i <= r && pry2 + j > 0 && pry2 + j <= c)
                vis[prx2 + i][pry2 + j] = false;
    vis[x][y] = false;
    g[x][y] = '.';
    at--;
}

int main(){
    scanf("%d %d", &r, &c);
    while(r != 0 || c != 0){
        for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            scanf(" %c", &g[i][j]);
        ans = 0;
        calc(1, 1, 0, 0, 0, 0);
        tt++;
        printf("Case %d:\n", tt);
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++)
                printf("%c", ga[i][j]);
            printf("\n"); 
        }
        printf("\n");
        scanf("%d %d", &r, &c);
    }
    return 0;
}