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
        string s;
        cin >> s;
        int l = 0, r = 0;
        vi freq[4];
        freq[1].pb(0), freq[2].pb(0), freq[3].pb(0);
        for(int i=0;i<s.size();i++){
            freq[1].pb(freq[1][i]), freq[2].pb(freq[2][i]), freq[3].pb(freq[3][i]);
            if(s[i] == '1') freq[1][i+1]++;
            if(s[i] == '2') freq[2][i+1]++;
            if(s[i] == '3') freq[3][i+1]++;
        }
        int mn = INF;
        bool ok = true;
        while(ok){
            while(!(freq[1][r+1] - freq[1][l]) or !(freq[2][r+1] - freq[2][l]) or !(freq[3][r+1] - freq[3][l])){
                r++;
                if(r >= s.size()){
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
            mn = min(mn,r - l + 1);
            while((freq[1][r+1] - freq[1][l]) and (freq[2][r+1] - freq[2][l]) and (freq[3][r+1] - freq[3][l])){
                mn = min(mn,r - l + 1);
                l++;
                if(l > s.size() - 3){
                    ok = false;
                    break;
                }
            }
            r++;
            if(r >= s.size()){
                ok = false;
                break;
            }
        }
        cout << (mn == INF ? 0 : mn) << "\n";
    }
    return 0;
}