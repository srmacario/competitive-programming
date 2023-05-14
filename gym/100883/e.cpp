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

map<int,int> id;

struct Node {
    Node* ch[2];
    Node () {
        memset(ch, 0, sizeof ch);
    }
};

Node* root;

void add (ll x) {
    Node* cur = root;
    for (ll j = 31; j >= 0; j--) {
        ll b = (((1ll << j)&x) > 0);
        if (!cur->ch[b]) cur->ch[b] = new Node();
        cur = cur->ch[b];
    }
}

ll query (ll x) {
    Node* cur = root;
    ll arrnum = 0;
    for (ll j = 31; j >= 0; j--) {
        ll b = (((1ll << j)&x) > 0);
        if (cur->ch[!b]) {
            cur = cur->ch[!b];
            if (!b) arrnum += (1ll << j);
        } else {
            cur = cur->ch[b];
            if (b) arrnum += (1ll << j);
        }
    }
    return arrnum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    id.clear();
    while(t--){
        root = new Node();
        int n, q;
        vi a;
        cin >> n >> q;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            a.pb(x);
            add(x);
        }
        for(int i=n-1;i>=0;i--) id[a[i]] = i+1;
        for(int i=0;i<q;i++){
            int y;
            cin >> y;
            cout << id[query(y)] << "\n";
        }
        delete root;
        cout << "\n";
    }
    return 0;
}