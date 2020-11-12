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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi ps(n+5);
        vector <pii> rp(n+5), lp(n+5); 
        for(int i=1;i<=n;i++){
            rp[i] = lp[i] = {0,0};
            cin >> ps[i];
            ps[i] += ps[i-1];
        }
        for(int r=1;r<=n;r++){
            for(int l=1;l<r;l++){
                int sum = ps[r] - ps[l-1];
                if(sum > n) continue;
                if(!lp[sum].st) lp[sum] = {l,r};
                rp[sum] = {l,r};
            }
        }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            //cout << i << ": " << lp[i].st << " " << lp[i].nd << " / " << rp[i].st << " " << rp[i].nd << "\n";
            int num = ps[i] - ps[i-1];
            if(i < lp[num].st or i > lp[num].nd and lp[num].st){
                //db(i);
                cnt++;
                continue;
            }
            if(i < rp[num].st or i > rp[num].nd and rp[num].st){
                //db(i);
                cnt++;
                continue;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}