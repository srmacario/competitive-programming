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

map<string, int> cnt, lst;

int main(){
    int n, k;
    cin >> n >> k;
    getchar();
    for(int i = 0; i < 3*n; i++){
        string l;
        getline(cin, l);
        cnt[l]++;
        lst[l] = i;
    }
    priority_queue <pair<pii, string>> pq;
    for(auto p : cnt){
        pair<pii, string> cur;
        cur.st.st = p.nd;
        cur.st.nd = lst[p.st];
        cur.nd = p.st;
        pq.push(cur);
    }
    for(int i = 0; !pq.empty() and i < k; i++){
        // db(pq.top().st.st _ pq.top().st.nd);
        cout << pq.top().nd << "\n";
        pq.pop();
    }
    return 0;
}