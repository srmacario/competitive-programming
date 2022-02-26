#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int f[N];

int main(){
    int n, m;
    scanf("%d%d",&n, &m);
    for(int i = 0; i < m; i++) scanf("%d", &f[i]);
    sort(f,  f + m);
    int ans = f[n-1] - f[0];
    for(int i = 0; i + n - 1 < m; i++){
        ans = min(ans, f[i + n - 1] - f[i]);
    }
    printf("%d\n", ans);
    return 0;
}