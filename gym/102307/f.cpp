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

char s[N];
int sign[N];
vector<pii> lvl;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main(){
    while(scanf(" %s", s)!=EOF){
        int sz = strlen(s);
        for(int i=0;i<N;i++) sign[i] = 1;
        int cnt = 0, cur = 1, inv = 1;
        while(cnt < sz){
            if(s[cnt] == '('){
                cur++;
                sign[cur] = sign[cur-1]*inv;
                inv = 1;
            }
            if(s[cnt] == ')') cur--;
            if(s[cnt] == '-') inv = -1;
            if(s[cnt] == '+') inv = 1;
            if(s[cnt] >= '0' and s[cnt] <= '9'){
                ll num = 0, den = 0, pot = 1;
                string snum, sden;
                while(s[cnt]>='0' and s[cnt]<='9'){
                    snum += s[cnt++];
                }
                for(int i=snum.size()-1;i>=0;i--){
                    num += (snum[i]-'0')*pot;
                    pot *= 10;
                }
                cnt++, pot = 1;
                while(s[cnt]>='0' and s[cnt]<='9'){
                    sden += s[cnt++];
                }
                for(int i=sden.size()-1;i>=0;i--){
                    den += (sden[i]-'0')*pot;
                    pot *= 10;
                }
                lvl.pb({inv*sign[cur]*num,den});
                cnt--;
            }
            cnt++;
        }
        int ansnum = lvl[0].st, ansden = lvl[0].nd, mdc;
        for(int i=1;i<lvl.size();i++){
            ansnum = ansnum*lvl[i].nd + lvl[i].st*ansden;
            ansden = ansden*lvl[i].nd;
            if(ansnum){
                mdc = gcd(abs(ansnum),ansden);
                ansnum /= mdc, ansden /= mdc;
            }
            else ansden = 1;
        }
        printf("%d/%d\n",ansnum,ansden);
        lvl.clear();
    }
    return 0;
}