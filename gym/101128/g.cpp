#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;
const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9  +7;
const int N = 105, M = 1005;

int p, k, gr[M][M];
vi pile[M];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> p >> k;
    for(int i=0;i<p;i++){
        int n;
        cin >> n;
        pile[i].pb(0);
        for(int j=1;j<=n;j++){
            int x;
            cin >> x;
            pile[i].pb(x);
        }
    }
    
    for(int i=0;i<p;i++){
        for(int j=1;j<pile[i].size();j++){
            vi mex(M);
            for(int l=0;l<=min(j-1,k);l++){
                int dif = (j-l) - pile[i][j-l];
                if(dif < 0) continue;
                else mex[gr[i][dif]]++;
            }
            for(int l=0;l<M;l++){
                if(!mex[l]){
                    gr[i][j] = l;
                    break;
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<p;i++){
        ans ^= gr[i][pile[i].size()-1];
    }
    cout << (ans ? "Alice can win." : "Bob will win.") << "\n";
    return 0;
}