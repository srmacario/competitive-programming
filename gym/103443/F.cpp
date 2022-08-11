#include<bits/stdc++.h>
using namespace std;

const int N = 8e3 + 5;

int n, xtl[N], xbr[N], ytl[N], ybr[N], c[N];
vector<int> vx, vy, g[N][N], del[N];
priority_queue<int> p[N];
bool ds[N], b[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d %d", &xtl[i], &ytl[i], &xbr[i], &ybr[i], &c[i]);
        vx.push_back(xtl[i]);
        vx.push_back(xbr[i]);
        vy.push_back(ytl[i]);
        vy.push_back(ybr[i]);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
    for(int i = 0; i < n; i++){
        xtl[i] = lower_bound(vx.begin(), vx.end(), xtl[i]) - vx.begin();
        xbr[i] = lower_bound(vx.begin(), vx.end(), xbr[i]) - vx.begin();
        ytl[i] = lower_bound(vy.begin(), vy.end(), ytl[i]) - vy.begin();
        ybr[i] = lower_bound(vy.begin(), vy.end(), ybr[i]) - vy.begin();
        for(int j = ybr[i]; j <= ytl[i]; j++)
            g[xtl[i]][j].push_back(i);
        del[xbr[i] + 1].push_back(i);
    }
    for(int i = 0; i < vx.size(); i++){
        for(int k : del[i])
            ds[k] = true;
        for(int j = 0; j < vy.size(); j++){
            for(int k : g[i][j])
                p[j].push(k);
            while(!p[j].empty() && ds[p[j].top()])
                p[j].pop();
            if(!p[j].empty())
                b[c[p[j].top()]] = true;
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++)
        if(b[i])
            ans++;
    printf("%d\n", ans);
    return 0;
}