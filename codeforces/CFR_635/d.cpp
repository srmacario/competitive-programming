#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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

ll sum(ll a, ll b, ll c){
    return (a-b)*(a-b) + (a-c)*(a-c) + (b-c)*(b-c);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int num[3];
        vi gems[3];
        cin >> num[0] >> num[1] >> num[2];
        for(int j=0;j<3;j++){
            for(int i=0;i<num[j];i++){
                int x;
                cin >> x;
                gems[j].pb(x);
            }
            sort(gems[j].begin(),gems[j].end());
        }
        ll ans = LINF;
        for(int j=0;j<3;j++){
            int sz1 = (j+1)%3, sz2 = (j+2)%3;
            for(int k=0;k<2;k++){
                for(int l=0;l<2;l++){
                    for(int i=0;i<num[j];i++){
                        int r1 = gems[j][i], t1, t2, t11, t12, t21, t22, m1, m2;
                        int s1 = (upper_bound(gems[sz1].begin(),gems[sz1].end(),r1) - gems[sz1].begin());
                        int s2 = (lower_bound(gems[sz1].begin(),gems[sz1].end(),r1) - gems[sz1].begin());
                        s1 = min(s1,num[sz1]-1), s2 = min(s2,num[sz1]-1);
                        t1 = gems[sz1][s1];
                        t2 = gems[sz1][s2];
                        if(r1 != t2) s2 = max(s2-1,0), t2 = gems[sz1][s2];
                        m1 = (r1 + t1 + l)/2;
                        m2 = (r1 + t2 + l)/2;
                        int s11 = (upper_bound(gems[sz2].begin(),gems[sz2].end(),m1) - gems[sz2].begin());
                        int s12 = (lower_bound(gems[sz2].begin(),gems[sz2].end(),m1) - gems[sz2].begin());
                        int s21 = (upper_bound(gems[sz2].begin(),gems[sz2].end(),m2) - gems[sz2].begin());
                        int s22 = (lower_bound(gems[sz2].begin(),gems[sz2].end(),m2) - gems[sz2].begin());
                        s11 = min(s11,num[sz2]-1), s12 = min(s12,num[sz2]-1), s21 = min(s21,num[sz2]-1), s22 = min(s22,num[sz2]-1);
                        t11 = gems[sz2][s11];
                        t12 = gems[sz2][s12];
                        t21 = gems[sz2][s21];
                        t22 = gems[sz2][s22];
                        if(m1 != t12) s12 = max(s12-1,0), t12 = gems[sz2][s12];
                        if(m2 != t22) s22 = max(s22-1,0), t22 = gems[sz2][s22];
                        ans = min(ans,sum(r1,t1,t11));
                        ans = min(ans,sum(r1,t1,t12));
                        ans = min(ans,sum(r1,t2,t21));
                        ans = min(ans,sum(r1,t2,t22));
                    }
                }
                swap(sz1,sz2);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}