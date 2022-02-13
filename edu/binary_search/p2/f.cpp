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

string a, b;
int n, p[N], mark[N];

bool check(int mid){
    for(int i = 0; i < mid; i++) mark[p[i]]++;
    string cur;
    for(int i = 0, l = 0; i < n; i++){
        if(!mark[i + 1] and a[i] == b[l]){
            cur += a[i], l++;
            if(l == b.size()) return true;
        }
    }
    for(int i = 0; i < mid; i++) mark[p[i]]--;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    n = a.size();
    for(int i = 0; i < n; i++) cin >> p[i];
    int l = 0, r = n;
    while(l < r){
        int mid = (l + r + 1) / 2;
        //cout << mid << "\n";
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout  << l << "\n";
    return 0;
}