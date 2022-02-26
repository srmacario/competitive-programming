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
const int N = 1e5+5, M = 1e9;

int cards(int h){
    return (3*h*h + h)/2;
}

int binS(int x, int l, int r){
    while(l < r){
        int m = (l+r+1)/2;
        if(cards(m) > x) r = m - 1;
        else l = m;
    }
    return cards(l);
}

int main(){
    int t;
    scanf("%d", &t);
    int l = 1, r = 1;
    while(cards(r) <= M) r++;
    while(t--){
        int n, cnt = 0;
        scanf("%d", &n);
        while(n >= 2){
            n -= binS(n, l, r);
            cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}