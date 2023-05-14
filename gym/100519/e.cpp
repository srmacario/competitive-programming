#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef long long ll;
typedef pair<ll, ll> pll;

ll n, d;
pll ans;
vector<ll> v;

int main(){
    scanf("%lld %lld", &n, &d);
    ll h = n - d;
    if(h <= d || h <= 1){
        if(n == d)
            printf("%lld 1\n", max(n + 1, 2ll));
        else
            printf("2 0\n");
    }
    else{
        for(ll i = 2; i * i <= h; i++){
            if(h % i)
                continue;
            if(i > d){
                int hh = 0;
                ll hhh = n;
                while(hhh % i == d){
                    hh++;
                    hhh /= i;
                }
                ans = max(ans, {hh, -i});
            }
            if(h / i != i && h / i > d){
                int hh = 0;
                ll j = h / i;
                ll hhh = n;
                while(hhh % j == d){
                    hh++;
                    hhh /= j;
                }
                ans = max(ans, {hh, -j});
            }
        }
        int hh = 0;
        ll hhh = n;
        while(hhh % h == d){
            hh++;
            hhh /= h;
        }
        ans = max(ans, {hh, -h});
        printf("%lld %lld\n", -ans.nd, ans.st);
    }
    return 0;
}