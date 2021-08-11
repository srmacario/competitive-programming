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
typedef pair<pii, int> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

int n, ans[N];
vector <piii> exam;


bool cmp_v (piii a, piii b){
    if(a.st.st == b.st.st) return a.st.nd > b.st.nd;
    return a.st.st < b.st.st;
}

struct cmp{
    bool operator() (piii a, piii b){
        //a < b
        return a.st.nd - a.st.st < b.st.nd - b.st.st;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        int t, c;
        cin >> t >> c;
        exam.pb({{t, c}, i});
    }
    sort(exam.begin(), exam.end(), cmp_v);

    priority_queue <piii, vector<piii>, cmp> pq;

    int pos = 0, cur = 1, cnt = 0;
    while(cnt < n or !pq.empty()){
        while(exam[pos].st.st == cur){
            pq.push(exam[pos]);
            ++cnt;
            ++pos;
        }
        if(!pq.empty()){
            ans[pq.top().nd] = cur;
            pq.pop();
        }
        cur++;
    }
    
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}