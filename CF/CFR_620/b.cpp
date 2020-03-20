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

vector<string> frt,bck,names;
int n,m;

int is_pal(){
    for(int i=0;i<n;i++){
        bool ok = true;
        for(int j=0;j<(m/2);j++){
            if(names[i][j] != names[i][m - j - 1]){
            ok = false;
            }
        }
        if(ok) return i;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        names.pb(s);
    }
    if(n == 0){
        cout << "0\n\n";
        return 0;
    }
    if(n == 1){
        int aux = is_pal();
        if(aux != -1) cout << names[aux].size() << "\n" << names[aux] << "\n";
        else cout << "0\n\n";
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
                bool ok = true;
                for(int k=0;k<m;k++){
                    if(names[i][k] != names[j][m - k - 1]){
                        ok = false;
                    }
                }
                if(ok){
                    frt.pb(names[i]), bck.pb(names[j]);
                }
                
        }
    }
    if(!frt.size() and !bck.size()){
        int aux = is_pal();
        if(aux != -1) cout << names[aux].size() << "\n" << names[aux] << "\n";
        else cout << "0\n\n";
        return 0;
    }
    int ans = 0;
    for(int i=0;i<frt.size();i++) ans+=frt[i].size();
    for(int i=bck.size()-1;i>=0;i--) ans+=bck[i].size();
    int pal = is_pal();
    if(pal!=-1) ans+=names[pal].size();
    cout << ans << "\n";
    for(int i=0;i<frt.size();i++) cout << frt[i];
    if(pal!=-1) cout << names[pal];
    for(int i=bck.size()-1;i>=0;i--) cout << bck[i];
    cout << "\n";
    return 0;
}