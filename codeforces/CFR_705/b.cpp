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
const int N = 1e5+5;

int mk[100], h, m;
map<int,int> id;

bool check(int hcur, int mcur){
    int mreal = id[hcur/10] + 10*id[hcur%10];
    int hreal = id[mcur/10] + 10*id[mcur%10];
    if(hreal < h and mreal < m) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    mk[0]++, id[0] = 0;
    mk[1]++, id[1] = 1;
    mk[2]++, id[2] = 5;
    mk[5]++, id[5] = 2;
    mk[8]++, id[8] = 8;
    while(t--){
        cin >> h >> m;
        string s;
        cin >> s;
        int hcur = (s[0]- '0')*10 + s[1] - '0';
        int mcur = (s[3]- '0')*10 + s[4] - '0';
        bool ok = false;
        while(!ok){
            if(mk[hcur/10] and mk[hcur%10] and mk[mcur/10] and mk[mcur%10]){
                if(check(hcur, mcur)){
                    ok = true;
                    break;
                }
            }
            mcur += 1;
            if(mcur == m){
                mcur = 0;
                hcur += 1;
                if(hcur == h) hcur = 0;
            }
        }
        cout << hcur/10 << hcur%10 << ":" << mcur/10 << mcur%10 << "\n";
    }
    return 0;
}