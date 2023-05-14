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

bool cmp (vi a, vi b){
    int i = 0;
    while(a[i] == b[i]) i++;
    return a[i] > b[i];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,k,v;
        cin >> n >> k >> v;
        vii cand(k);
        for(int i=0;i<k;i++) cand[i].resize(v+2), cand[i][v+1] = k - (i+1);
        for(int i=0;i<n;i++){
            int l;
            cin >> l;
            for(int j=1;j<=l;j++){
                int x;
                cin >> x;
                if(x > k or x < 1 or j > v) continue;
                cand[x-1][0]++, cand[x-1][j]++;
            }
        }
        sort(cand.begin(),cand.end(),cmp);
        for(int i = 0; i < v; i++){
            //for(int j=0;j<v+1;j++) cout << cand[i][j] << " ";
            cout << k - (cand[i][v+1]);
            cout << " ";
            //db(i);
        }
        for(int i=v;i<k;i++){
            bool ok = true;
            for(int j=0;j<v+1;j++) if(cand[i][j] != cand[i-1][j]) ok = false;
            if(ok) cout << k - (cand[i][v+1]) << " ";
            else break;
        }
        cout << "\n";
    }
    return 0;
}