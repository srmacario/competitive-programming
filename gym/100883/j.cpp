#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 40, M = 1e6+10;
vector <ll> palp[N], pal[N], ans;
int cmp[M];
vector<ll> pr;

void primes(){
    for(ll i = 2; i < M; i++) if(!cmp[i]){
        for(ll j = i*i;j < M; j+=i) cmp[j] = 1;
        pr.pb(i);
    }
}

void tobin(ll n){
    ll cnt = 0;
    for(int i=31;i>=0;i--){
        if((1ll<<i) & n) printf("1"), cnt++;
        else if (cnt) printf("0");
    }
    printf("\n");
}

int main(){
    primes();
    pal[0].pb(2), pal[0].pb(0);
    pal[1].pb(0), pal[1].pb(6), palp[1].pb(3);
    ll cnt = 0;
    for(ll i=2;i<=31;i++){
        for(ll j=0;j<pal[i-2].size();j++){
            ll k = (1 + (1ll<<i) + pal[i-2][j]);
            cnt++;
            palp[i].pb(k);
            pal[i].pb(2*k);
            pal[i].pb(2*pal[i-2][j]);
        }
    }
    for(ll i=0;i<=31;i++){
        for(ll j=0;j<palp[i].size();j++){
            bool ok = true;
            ll num = palp[i][j];
            for(ll k = 0; k<pr.size(); k++){
                if(pr[k]*pr[k] > num) break;
                if(!(num%pr[k])) ok = false;
            }
            if(ok) ans.pb(num);
        }
    }
    sort(ans.begin(),ans.end());
    char str[50];
    while(scanf("%s",str) != EOF){
        ll b = 0;
        for(int i=0;i<strlen(str);i++){
            ll sz = strlen(str);
            if(str[i]-'0') b += (1ll<<(sz-i-1));
        }
        auto low = lower_bound(ans.begin(),ans.end(),b+1);
        b = ans[(low - ans.begin())];
        tobin(b);
    }
    return 0;
}