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
const int N = 2e5+5;

int occ[2*N], has[2*N];

bool cmp(pii a, pii b){
    if(a.st == b.st){
        return occ[a.nd] > occ[b.nd];
    }
    return occ[a.st] < occ[b.st];
}

int main(){
    int n;
    scanf("%d",&n);
    vector<pii> cards;
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        occ[a]++;
        if(a!=b)occ[b]++;
        cards.pb({a,b});
    }
    for(int i=0;i<n;i++){
        if(occ[cards[i].st] > occ[cards[i].nd]) swap(cards[i].st, cards[i].nd);
    }
    sort(cards.begin(),cards.end(),cmp);
    int ans = 0;
    for(auto p : cards){
        if(p.st == p.nd){
            if(!(has[p.st]++)) ans++;
        }
    }
    for(auto p : cards){
        if(has[p.st]){
            if(!has[p.nd]) ans++;
            has[p.nd]++;
        }
        else{
            has[p.st]++;
            ans++;
        } 
    }
    cout << ans << "\n";
    return 0;
}