#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 8e3 + 5, M = 4e3 + 5;

int n;
bool mark[M], off[N];
int xtl[N], xbr[N], ytl[N], ybr[N], c[M];
priority_queue<int> pq[N];

vector<int> vx, vy, del[N], ins[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d%d", &xtl[i], &ytl[i], &xbr[i], &ybr[i]);
        vx.push_back(xtl[i]);
        vx.push_back(xbr[i]);
        vy.push_back(ytl[i]);
        vy.push_back(ybr[i]);

        scanf("%d", &c[i]);
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
        ins[xtl[i]].push_back(i);
        del[xbr[i]].push_back(i);
    }
    for(int i = 0; i < vx.size() - 1; i++){
        
        for(int j : ins[i]){
            for(int k = ybr[j]; k < ytl[j]; k++){
                pq[k].push(j);
            }
        }
        for(int j : del[i]) off[j] = true;

        for(int j = 0; j < vy.size() - 1; j++){
            while(!pq[j].empty() and off[pq[j].top()]) pq[j].pop();
            if(!pq[j].empty()) mark[c[pq[j].top()]] = true;
        }
    }
    int ans = 0;
    for(int i = 0; i < M; i++) ans += mark[i];
    printf("%d\n", ans);
    return 0;
}