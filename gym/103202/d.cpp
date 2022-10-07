#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int q, n;
ll ma;
char s[N];

void calc(int p, ll si, ll sp, ll st){
    ll f = n - p;
    if(st + f * max(si, sp) + f * (f + 1) / 2 < ma)
        return;
    if(q == 100)
        return;
    if(p == n){
        if(st == ma){
            for(int i = 0; i < n; i++)
                printf("%c", s[i]);
            q++;
            printf("\n");
        }
        return;
    }
    s[p] = 'b';
    calc(p + 1, si, sp + 1, st + si);
    s[p] = 'r';
    calc(p + 1, sp + 1, si, st + sp + 1);
}

int main(){
    scanf("%d", &n);
    if(n & 1)
        ma = ((n + 1) / 2) * ((n + 1) / 2);
    else
        ma = (n / 2) * (n / 2 + 1);
    printf("%lld\n", ma);
    calc(0, 0, 0, 0);
    return 0;
}