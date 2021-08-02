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
const int N = 3e5+5, M = 2e3+5;

int n, q;
int px[M], py[M];
int qx[N], qy[N];
int cnt[N], ans[N];
pii reg[N];

int main(){
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &px[i], &py[i]);
    }
    for(int i = 0; i < q; i++){
        scanf("%d%d", &qx[i], &qy[i]);
    }
    for(int i = 0; i < q; i++){
        ans[i] = INF;
        for(int j = 0; j < n; j++){
            int d2 = (px[j]-qx[i])*(px[j]-qx[i]) + (py[j]-qy[i])*(py[j]-qy[i]);
            if(d2 < ans[i]) ans[i] = d2, cnt[i] = 1, reg[i].st = j + 1;
            else if(d2 == ans[i]) cnt[i]++, reg[i].nd = reg[i].st, reg[i].st = j + 1;
        }
    }
    for(int i = 0; i < q; i++){
        if(cnt[i] >= 3) printf("POINT\n");
        else if(cnt[i] == 2){
            if(reg[i].st > reg[i].nd) swap(reg[i].st, reg[i].nd);
            printf("LINE %d %d\n", reg[i].st, reg[i].nd);
        }
        else if(cnt[i] == 1) printf("REGION %d\n", reg[i].st);
    }
    return 0;
}