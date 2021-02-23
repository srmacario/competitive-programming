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
const int N = 1e4+5, K = 1e3+5;

int freq[K], s[N], cnt;
vi times[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n,lo,mid,hi;
    cin >> k >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
        freq[s[i]]++;
    }
    for(int i=1;i<=k;i++){
        times[freq[i]].pb(i);
        if(times[freq[i]].size() == 1){
            cnt++;
            if(cnt == 1) lo = freq[i];
            if(cnt == 2){
                if(freq[i] > lo) mid = freq[i];
                else mid = lo, lo = freq[i];
            }
            if(cnt == 3){
                if(freq[i] > mid) hi = freq[i];
                else{
                    hi = mid;
                    if(freq[i] > lo) mid = freq[i];
                    else mid = lo, lo = freq[i];
                }
            }
        }
    }
    if(cnt > 3){
        cout << "*\n";
    }
    if(cnt == 3){
        if(times[lo].size() == 1 and times[hi].size() == 1){
            if(mid - lo == 1 and hi - mid == 1){
                cout << -times[hi].back() << " +" << times[lo].back() << "\n";
                return 0;
            }
        }
        cout << "*\n";
    }
    if(cnt == 2){
        if(times[lo].size() == 1){
            if((mid - lo) == 1){
                cout << "+" << times[lo].back() << "\n";
                return 0;
            }
        }
        if(times[mid].size() == 1){
            if(mid - lo == 1){
                cout << -times[mid].back() << "\n";
                return 0;
            }   
            if(mid - lo == 2 and times[lo].size() == 1){
                cout << -times[mid].back() << " +" << times[lo].back() << "\n";
                return 0;
            }
        }
        cout << "*\n";
    }
    return 0;
}