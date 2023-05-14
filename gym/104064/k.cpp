#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n, tot;
int sock[N][3];
map<string, int> id;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        string t, s;
        int qtd;
        cin >> t >> s >> qtd;
        if(!id.count(t)) id[t] = i;
        int w = 0;
        if(s == "left") w = 1;
        if(s == "right") w = 2;
        sock[id[t]][w] = qtd;
        tot += qtd;
    }
    int cnt = 0;
    for(auto p : id){
        if(sock[p.nd][1] == 0 and sock[p.nd][2] == 0){
            cnt++;
            continue;
        }
        cnt += max(sock[p.nd][1], sock[p.nd][2]);
    }
    if(cnt == tot){
        cout << "impossible\n";
        return 0;
    }
    cout << cnt + 1 << "\n";
    return 0;
}