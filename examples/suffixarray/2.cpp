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
typedef pair<pii,int> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

void radix_sort(vector <piii> &o){
    int n = o.size();
    vi cnt(n,0), pos(n,0);
    //counting sort for second element of pair
    //init bucket size
    for(auto x : o) cnt[x.st.nd]++;
    //init first empty position to each bucket
    for(int i=1;i<n;i++) pos[i] = pos[i-1] + cnt[i-1];
    //count
    vector <piii> o_new(n);
    for(auto x : o){
        int i = x.st.nd;
        o_new[pos[i]++] = x;
    }
    //trade o for o_new to redo the process for the first element of pair
    o = o_new;
    for(int i=0;i<n;i++) pos[i] = cnt[i] = 0;
    for(auto x : o) cnt[x.st.st]++;
    for(int i=1;i<n;i++) pos[i] = pos[i-1] + cnt[i-1];
    for(auto x : o){
        int i = x.st.st;
        o_new[pos[i]++] = x;
    }
    o = o_new;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    vi p(n), c(n);
    //base
    //sorting base vector by character
    vector <pair<char,int>> ord;
    for(int i=0;i<n;i++) ord.pb({s[i],i});
    sort(ord.begin(), ord.end());
    for(int i=0;i<n;i++) p[i] = ord[i].nd;
    //creating equivalence classes
    c[p[0]] = 0;
    for(int i=1;i<n;i++){
        if(ord[i].st == ord[i-1].st) c[p[i]] = c[p[i-1]];
        else c[p[i]] = c[p[i-1]] + 1;
    }
    //recursion
    int k = 0;
    while((1ll<<k) < n){
        //sorting base vector by pair of integers: [s[i] + s[i+2^k]]
        vector <piii> o;
        for(int i=0;i<n;i++) o.pb({{c[i], c[(i + (1ll<<k))%n]},i});
        radix_sort(o);
        for(int i=0;i<n;i++) p[i] = o[i].nd;
        //creating equivalence classes
        c[p[0]] = 0;
        for(int i=1;i<n;i++){
            if(o[i].st == o[i-1].st) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
        }
        k++;
    }
    for(int i=0;i<n;i++) cout << p[i] << " ";
    cout << "\n";
    return 0;
}