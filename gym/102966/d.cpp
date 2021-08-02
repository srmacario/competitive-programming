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

const int N = 1e6+10; // Upper limit to n

int cmp[N];
vi pr;


void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j += i) cmp[j] = 1;
        pr.pb(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    primes();
    int t;
    cin >> t;
    while(t--){
        ll k;
        cin >> k;
        set<int> ans;
        k+=2;
        for(int i = 0; k >= pr[i]*pr[i]; i++){
            while(!(k%pr[i])){
                k/=pr[i];
                if(pr[i] != 2) ans.insert(pr[i]);
            }
        }
        if(k > 2) ans.insert(k);
        if(!ans.size()) cout << "-1";
        else{
            int cnt = 0;
            for(auto s : ans){
                cout << s;
                if(cnt != ans.size()-1) cout << " ";
                ++cnt;
            }
        }
        cout << "\n";
    }
    return 0;
}