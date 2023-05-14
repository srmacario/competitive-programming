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

pll pts[N];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&pts[i].st, &pts[i].nd);
    }
    ll areat = 0, areah = 0;
    for(int i=0;i<n;i++){
        areat += pts[i].st*pts[(i+1)%n].nd-pts[(i+1)%n].st*pts[i].nd;
    }
    int j = 1;
    areah += pts[j-1].st*pts[j].nd - pts[j].st*pts[j-1].nd;
    ll best = 0;
    for(int i=0;i<n;i++){
        ll ans = LINF;
        if(i){
            areah -= pts[i-1].st*pts[i].nd - pts[i].st*pts[i-1].nd;
        }
        while(true){
            areah += pts[j].st*pts[i].nd - pts[i].st*pts[j].nd;
            if((j-i+n)%n < 2){
                areah -= pts[j].st*pts[i].nd - pts[i].st*pts[j].nd;
                j = (j+1)%n;
                areah += pts[(j-1+n)%n].st*pts[j].nd - pts[j].st*pts[(j-1+n)%n].nd;
                continue;
            }
            ll dif = abs(2*areah-areat);
            if(dif < ans){
                ans = dif;
                areah -= pts[j].st*pts[i].nd - pts[i].st*pts[j].nd;
                j = (j+1)%n;
                areah += pts[(j-1+n)%n].st*pts[j].nd - pts[j].st*pts[(j-1+n)%n].nd;
            }
            else{
                areah -= pts[j].st*pts[i].nd - pts[i].st*pts[j].nd;
                areah -= pts[(j-1+n)%n].st*pts[j].nd - pts[j].st*pts[(j-1+n)%n].nd;
                j = (j-1+n)%n;
                break;
            }
        }
        best = max(ans,best);
    }
    ll ans = (areat+best)/2;
    printf("%lld %lld\n",ans,areat-ans);
    return 0;
}