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
const int N = 1e5+5;

void count_sort(vi &p, vi &c){
    //sort array p by keys in c, since c is already sorted.
    int n = p.size();
    vi cnt(n,0), pos(n,0), p_new(n,0);
    //init bucket size
    for(auto x : c) cnt[x]++;
    //init first empty position to each bucket
    for(int i=1;i<n;i++) pos[i] = pos[i-1] + cnt[i-1];
    //count
    for(auto x : p){
        int i = c[x];
        p_new[pos[i]++] = x;
    }
    p = p_new;
}

vi suffix(string s){
    int n = s.size();
    vi p(n,0), c(n,0);
    //base
    //sorting base vector by character
    vector <pair<char,int>> ord;
    for(int i=0;i<n;i++) ord.pb({s[i],i});
    sort(ord.begin(), ord.end());
    for(int i=0;i<n;i++) p[i] = ord[i].nd;
    //creating equivalence classes
    for(int i=1;i<n;i++){
        if(ord[i].st == ord[i-1].st) c[p[i]] = c[p[i-1]];
        else c[p[i]] = c[p[i-1]] + 1;
    }
    //recursion
    int k = 0;
    while((1ll<<k) < n){
        //sorting base vectors by pair of integers: [s[i-2^k], s[i]]
        // c is already sorted (means second element of pair)
        // shift p 2^k left to correspond first part
        for(int i=0;i<n;i++) p[i] = (p[i]-(1ll<<k)+n)%n;
        //counting sort array p by elements in c
        count_sort(p,c);
        //creating new equivalence classes
        vi c_new(n,0);
        for(int i=1;i<n;i++){
            //comparing current pair with old one
            pii old, cur;
            old = {c[p[i-1]],c[(p[i-1]+(1ll<<k))%n]};
            cur = {c[p[i]],c[(p[i]+(1ll<<k))%n]};
            if(old == cur) c_new[p[i]] = c_new[p[i-1]];
            else c_new[p[i]] = c_new[p[i-1]] + 1;
        }
        c = c_new;
        k++;
    }
    return p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string t;
    //read t, add '$' and calculate its suffix array
    cin >> t;
    t += "$";
    vi suf = suffix(t);
    int n, sz;
    //disconsider suffix '$' which is position 0, so size is:
    sz = suf.size()-1;
    cin >> n;
    while(n--){
        bool ok = false;
        string s;
        cin >> s;
        int szi = s.size();
        //with sz = suf.size()-1 and disconsidering suf[0], boundaries are:
        int l = 1, r = sz;
        while(l<=r){
            int mid = (l+r)/2;
            //if size of string i is greater than our suffix, we only compare the last sz-suf[mid] elements of our string i
            if(szi > sz - suf[mid]){
                string sub = t.substr(suf[mid],sz-suf[mid]);
                string temp = s.substr(0,sz-suf[mid]);
                if(s >= sub) l = mid+1;
                else r = mid-1;
            }
            //else, we reduce our suffix size to szi and compare
            else{
                string sub = t.substr(suf[mid],szi);
                //in this case if its equals it means we already found our substring
                if(s == sub){
                    ok = true;
                    break;
                }
                else if(s > sub) l = mid + 1;
                else r = mid -1;
            }
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}