#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;

const int N = 3e5 + 5;
const long long LINF = 0x3f3f3f3f3f3f3f3f;

int n, m, c[N], d[N], k[N], day[N], x, pt[N];
pii p[N];
long long dp[N];

int main(){
    scanf("%d %d %d", &n, &m, &c[0]);
    d[0] = k[0] = 1;
    for(int i = 1; i <= n; i++)
        scanf("%d %d %d", &d[i], &k[i], &c[i]);
    for(int i = 0; i < m; i++)
        scanf("%d %d", &p[i].st, &p[i].nd);
    sort(p, p + m);
    for(int i = 0; i < m; i++)
        while(p[i].nd--){
            day[x] = p[i].st;
            x++;
        }
    for(int i = 1; i <= x; i++)
        dp[i] = LINF;
    for(int i = 0; i < x; i++)
        for(int j = 0; j <= n; j++){
            while(pt[j] < x && day[pt[j]] < day[i] + d[j])
                pt[j]++;
            int nxt = min(pt[j], i + k[j]);
            dp[nxt] = min(dp[nxt], dp[i] + c[j]);
        }
    printf("%lld\n", dp[x]);
    return 0;
}