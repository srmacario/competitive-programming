#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
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
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7+5;

string s, cur, base, xp;
ll ps[N], f[N];

void add(string num){
    bool fat = false;
    int x = 0;
    if(num.back() == '!') fat = true, num.pop_back();
    x = stoi(num);
    ps[x + 1] = (ps[x + 1 ] - 1ll)%2;
    if(fat) ps[2] = (ps[2] + 1ll)%2;
    else ps[x] = (ps[x] + 1ll)%2;
}

bool odd_xp(string num){
    if(num.empty()) return false;
    if(num.back() == '!'){
        num.pop_back();
        if(num.back() == '1' and num.size() == 1) return true;
        return false;
    }
    if(!((num.back() - '0')%2)) return false;
    return true;
}

void check_base(){
    if(base.size() and xp.empty()) xp = cur;
    if(xp.size() and odd_xp(xp)){
        add(base);
    }
    if(cur.size() and xp.empty()){
        add(cur);
    }
    base.clear(), xp.clear();
}

ll p[N];
vector<ll> primes;

void sieve(){
    for (ll i = 2; i < N; ++i) if (!p[i]) {
    for (ll j = i*i; j < N; j+=i) p[j]=1;
        primes.pb(i);
    }
}

void fact(ll x, ll k){
    if(!k) return;
    for(int i = 0; i < primes.size() and primes[i] * primes[i] <= x; i++){
        while(!(x%primes[i])) x /= primes[i], f[primes[i]] = (f[primes[i]] + k)%2;
    }
    if(x != 1) f[x] = (f[x] + k)%2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        //divide em numero e * ou ^
        if(s[i] == '!' or (s[i] >= '0' and s[i] <= '9')) cur += s[i];
        else{
            if(s[i] == '*'){
                check_base();
            }
            //so importa a base e o primeiro expoente
            else{
                if(base.empty()) base = cur;
                else if(xp.empty()) xp = cur;
            }
            cur.clear();
        }
    }
    check_base();
    sieve();
    //fatora todo mundo
    for(int i = 1; i < N; i++){
        ps[i] = (ps[i] + ps[i - 1])%2;
        fact(i, ps[i]);
    }
    //ve se ficou algum termo impar
    for(int i = 2; i < N; i++){
        if(f[i]%2){
            cout << "N\n";
            return 0;
        }
    }
    cout << "S\n";
    return 0;
}