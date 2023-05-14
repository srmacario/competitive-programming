#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 4e5 + 5;

int n, a[N], q[N], c[N];
bool vis[N];
vector<int> v;
bitset<N> b1, b2;

void calc(){
    for(int i = 1; i <= n; i++){
        if(!vis[i])
            continue;
        pii ans = {0, 0};
        b1 = 0;
        b2 = 0;
        for(int j = c[i] + 1; j < n; j++){
            if(v[j] == i)
                b1 |= b2;
            else{
                b2[a[j]] = true;
                if(b1[a[j]])
                    ans = max(ans, {i, -a[j]});
            }
        }
        if(ans != make_pair(0, 0)){
            printf("%d %d\n", ans.st, -ans.nd);
            return;
        }
    }
    printf("-1\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        q[a[i]]++;
    }
    for(int i = 0; i < n; i++)
        if(q[a[i]] > 1){
            if(!vis[a[i]])
                c[a[i]] = v.size();
            v.push_back(a[i]);
            vis[a[i]] = true;
        }
    calc();
    return 0;
}