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
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n,l,r;
        cin >> n >> l >> r;
        ll sum = 0, cnt = 1;
        ll md = 0;
        for(int i=1;i<=n-1;i++){
            md += (n-i)*2;
        }
        bool ok = false;
        if(l == md) ok = true;
        ll dist = (r-l);
        l = l%md;
        for(int i = 1;i<=n-1;i++){
            sum += (n-cnt)*2;
            if(l <= sum) break;
            cnt++;
        }
        ll aux = 0;
        if(ok) {cout << n << " "; aux++;}
        ll laux = sum - (n-cnt)*2 + 1;
        while(aux <= dist){
            ll carry = 1;
            for(int i=1;i<=(n-cnt)*2;i++){
                if(aux > dist) break;
                if(laux >= l) aux++;
                if(i%2){
                    if(laux >= l) cout << cnt << " ";
                }
                if(!(i%2)){
                    if(laux >= l){
                        cout << cnt + carry << " ";
                    }
                    carry++;
                }
                laux++;
            }
            cnt++;
            if(laux > md) laux = l = 1, cnt = 1;
        }
        cout << "\n";
    }
    return 0;
}