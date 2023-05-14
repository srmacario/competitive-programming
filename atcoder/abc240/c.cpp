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
const int N = 1e4+5;

int pos[N], oldpos[N];
int a[2][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    oldpos[0] = pos[0] = 1;
    for(int i = 0; i < n; i++) cin >> a[0][i] >> a[1][i];
    for(int i = 0; i < n; i++){
        for(int k = 0; k < 2; k++){
            for(int j = N - 1; j >= 0; j--){
                if(oldpos[j] and j + a[k][i] < N) pos[j + a[k][i]]++;
            }
        }
        for(int j = N - 1; j >= 0; j--){
            if(oldpos[j]) pos[j] -= oldpos[j];
            oldpos[j] = pos[j];
        }
    }
    if(pos[x]) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}