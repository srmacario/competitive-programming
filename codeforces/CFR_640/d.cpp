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
        vi a,ps;
        a.pb(0), ps.pb(0);
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            a.pb(x);
            ps.pb(ps[i] + x);
        }/*
        for(int i=0;i<=n;i++){
            cout << ps[i] << " ";
        }*/
        //cout << "\n";
        ll suma = 0, sumb = 0, now = 0, carry = 0, cnt = 0;
        ll l = 1, r = n;
        while(l<=r){
            //db(l), db(r);
            if(now){
                ll aux = r;
                while(ps[r] - ps[aux-1] <= carry and aux != l){
                    aux--;
                }
                carry = ps[r] - ps[aux-1];
                //db(carry);
                sumb += carry;
                r = aux - 1;
            }
            else{
                ll aux = l;
                while(ps[aux] - ps[l-1] <= carry and aux != r){
                    aux++;
                }
                carry = ps[aux] - ps[l-1];
                //db(carry);
                suma += carry;
                l = aux + 1;
            }
            now = now^1;
            cnt++;
        }
        cout << cnt << " " << suma << " " << sumb << "\n";
    }
    return 0;
}