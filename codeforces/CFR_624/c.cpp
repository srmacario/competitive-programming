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
        int n,m,freq[30] = {0};
        vi sum;
        cin >> n >> m;
        for(int i=0;i<=n;i++){
            sum.pb(0);
        }
        string s;
        cin >> s;
        for(int i=0;i<m;i++){
            int x;
            cin >> x;
            sum[0] += 1, sum[x] -= 1;
        }
        sum[0] += 1, sum[n] = -1;
        for(int i=1;i<=n;i++){
            sum[i] = sum[i] + sum[i-1];
        }
        for(int i=0;i<n;i++){
            freq[s[i] - 'a'] += sum[i];
        }
        for(int i=0;i<26;i++){
            cout << freq[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}