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
const int N = 105;

char u[N], resp[N];
int cnt[N], n, lft;
bool chn;

bool bt(int pos, int cur){
    if(pos == n){
        for(int i=lft;i<n;i++) printf("%c",resp[i]);
        printf("\n");
        return true;
    }
    int nxt = u[pos+1] - '0';
    if(chn) nxt = 9;
    while(cur >= 0){
        if(pos == lft and cur == 0){
            lft++;
            return bt(pos+1,nxt);
        }
        if(cnt[cur] < 2){
            resp[pos] = cur + '0';
            cnt[cur]++;
            bool ok = bt(pos+1, nxt);
            if(ok == true) return true;
            cnt[cur]--;
        }
        cur--;
        nxt = 9;
        chn = true;
    }
    return false;
}


int main(){
    scanf("%s",u);
    n = strlen(u);
    bt(0,u[0] - '0');
    return 0;
}