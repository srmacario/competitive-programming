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

map<string, pii> prob, cand;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c,p,s;
    cin >> c >> p >> s;
    for(int i=0; i<c; i++){
        string s;
        cin >> s;
        cand[s] = {0,1};
    }
    for(int i=0;i<p;i++){
        string s;
        int v;
        cin >> s >> v;
        prob[s] = {v,1};
    }
    for(int i=0;i<s;i++){
        string u,p,v;
        cin >> u >> p >> v;
        if(!cand[u].nd) continue;
        if(v == "AC" and prob[p].nd) cand[u].st += prob[p].st;
    }
    for(auto u: cand){
        if(!u.nd.nd) continue;
        cout << u.st << " " << u.nd.st << "\n";
    }
    return 0;
}