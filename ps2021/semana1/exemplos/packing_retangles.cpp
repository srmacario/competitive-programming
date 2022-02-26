#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ll n, w, h;
    scanf("%lld%lld%lld", &w, &h, &n);
 
    //condicao para descartar: x/a * x/b < n
    ll l = 0, r = 1;
    //procura pelo r de forma segura
    while((r/w) * (r/h) < n) r *= 2;
    //lower_bound
    while(l < r){
        ll m = (l+r)/2;
        if((m/w) * (m/h) < n) l = m + 1;
        else r = m;
    }
    printf("%lld\n", l);
}