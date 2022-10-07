#include<bits/stdc++.h>
using namespace std;

long long h, m, a, ra, ans;

int main(){
    scanf("%lld %lld %lld", &h, &m, &a);
    if(2 * a == h * m){
        printf("%lld\n", h * m);
        return 0;
    }
    ra = a % m;
    a = a / m;
    h = (h - 1) % m;
    ans = m * (2 * a + 1) + (ra / __gcd(m, h)) * __gcd(m, h) - ((m - ra - 1) / __gcd(m, h)) * __gcd(m, h);
    printf("%lld\n", ans);
    return 0;
}