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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int cur = 0, pts[2] = {0}, gms[2] = {0};
    bool ok = false;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'S'){
            if(ok) continue;
            pts[cur]++;
            if(pts[cur] == 10 or (pts[cur] >= 5 and pts[cur] >= pts[cur^1] + 2)){
                gms[cur]++;
                pts[0] = pts[1] = 0;
                if(gms[cur] == 2) ok = true;
            }
        }
        else if(s[i] == 'R'){
            if(ok) continue;
            cur ^= 1;
            pts[cur]++;
            if(pts[cur] == 10 or (pts[cur] >= 5 and pts[cur] >= pts[cur^1] + 2)){
                gms[cur]++;
                pts[0] = pts[1] = 0;
                if(gms[cur] == 2) ok = true;
            }
        }
        else{
            if(ok){
                cout << gms[0] << (gms[0] == 2 ? " (winner) " : " ");
                cout << "- ";
                cout << gms[1] << (gms[1] == 2 ? " (winner) " : " ");
                cout << "\n";
            }
            else{
            cout << gms[0] << " (" << pts[0] << (cur == 0 ? "*": "")<< ") ";
            cout << "- ";
            cout << gms[1] << " (" << pts[1] << (cur == 1 ? "*": "") << ") ";
            cout << "\n";
            }
        }
    }
    return 0;
}