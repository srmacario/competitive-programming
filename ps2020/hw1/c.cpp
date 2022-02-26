#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9;

int main(){
    set <ll> s;
    int n;
    scanf("%d",&n);
    char last = '+', op;
    ll y, mx = -1;
    for(int i=0;i<n;i++){
        ll k;
        char t;
        scanf(" %c%c%lld",&op,&t,&k);
        if(op == '?'){
            y = *(s.upper_bound(k));
            if(mx < k) y = -1;
            if(s.count(k)) y = k;
            printf("%lld\n",y);
        }
        if(op == '+'){
            if(last == '+')s.insert(k), mx = max({mx,k});
            else s.insert((k+y)%MOD), mx = max({mx,(k+y)%MOD});
        }
        last = op;
    }
    return 0;
}