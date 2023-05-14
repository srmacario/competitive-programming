#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
const ll MOD = 1e9 + 7;

int t, a, b, c, k, cz;
ll fat[N], ifat[N], inv[N];

ll esc(int x, int y){
    if(y > x)
        return 0;
    return fat[x] * ifat[y] % MOD * ifat[x - y] % MOD;
}

int main(){
    inv[1] = fat[0] = ifat[0] = 1;
    for(int i = 2; i < N; i++)
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    for(int i = 1; i < N; i++){
        fat[i] = fat[i - 1] * i % MOD;
        ifat[i] = ifat[i - 1] * inv[i] % MOD;
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d %d", &a, &b, &c, &k, &cz);
        if(k - cz < 2 || a + b + cz < k)
            printf("0\n");
        else
           printf("%lld\n", (esc(c, cz) * (esc(a + b, k - cz) - esc(a, k - cz) - esc(b, k - cz)) % MOD + MOD) % MOD);
    }
    return 0;
}