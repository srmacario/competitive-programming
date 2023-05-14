#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
const int N = 2e5+5;

ll bit1[N], bit2[N], pos[N], vel[N];
vector <pll> car, c_x, c_v;

int n;

void add1(ll p, ll v) {
    for (p+=2; p<N; p += p&-p) bit1[p] += v;
}

ll query1(ll p) {
    ll r = 0;
    for (p+=2; p; p -= p&-p) r += bit1[p];
    return r;
}

ll rangesum1(ll a, ll b) {
    return query1(b)-(a ? query1(a-1) : 0);
}

void add2(ll p, ll v) {
    for (p+=2; p<N; p += p&-p) bit2[p] += v;
}

ll query2(ll p) {
    ll r = 0;
    for (p+=2; p; p -= p&-p) r += bit2[p];
    return r;
}

ll rangesum2(ll a, ll b) {
    return query2(b)-(a ? query2(a-1) : 0);
}

bool cmp(pll a, pll b){
    return a.nd < b.nd;
}

void compress(){
    sort(car.begin(), car.end());
    ll aux = 1, carry;
    carry = car[0].st;
    car[0].st = aux;
    for(int i=1;i<n;i++){
        if(car[i].st != carry) aux++;
        carry = car[i].st;
        car[i].st = aux;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++) cin >> pos[i];
    for(int i=0;i<n;i++) cin >> vel[i];
    for(int i=0;i<n;i++){
        car.pb({vel[i],pos[i]});
    }
    compress();
    sort(car.begin(),car.end(),cmp);
    //for(int i=0;i<n;i++){
      //  cout << car[i].st << " " << car[i].nd << "\n";
    //}
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += -rangesum1(1,car[i].st) + rangesum2(1,car[i].st)*car[i].nd;
        add1(car[i].st,car[i].nd);
        add2(car[i].st,1);
        //cout << ans << "\n";
    }
    cout << ans << "\n";
    return 0;
}