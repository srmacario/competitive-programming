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

vi v;
int revid[N];
map<int, int> id;

int main(){
    int n;
    scanf("%d", &n);
    v.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    //lembre de manter uma copia do vetor original!
    //ordena
    sort(v.begin(), v.end());
    //deixa so os unicos
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
    for(int i = 0; i < v.size(); i++){
        //mapeia com um novo valor
        id[v[i]] = i;
        //id reverso para recuperar depois
        revid[i] = v[i];
    }
    return 0;
}