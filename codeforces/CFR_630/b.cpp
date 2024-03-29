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
const int N = 1e6+5;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int a[N], color[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            color[i] = 0;
        }
        int cnt = 1;
        for(int i=1;i<=n;i++){
            if(!color[i]) color[i] = cnt++;
            else continue;
            for(int j=i+1;j<=n;j++){
                if(gcd(a[i],a[j]) > 1) {
                    if(!color[j]){
                        color[j] = color[i];
                    }
                }
            }
        }
        db(gcd(731,697));
        cout << cnt-1 << "\n";
        for(int i=1;i<=n;i++) cout << color[i] << " ";
        cout << "\n";
    }
    return 0;
}