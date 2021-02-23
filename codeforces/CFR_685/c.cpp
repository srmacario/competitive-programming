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
const int N = 1e6+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string a,b;
        int n,k;
        cin >> n >> k >> a >> b;
        int psa[26] = {0}, psb[26] = {0};
        for(int i=0;i<n;i++){
            psa[a[i]-'a']++;
            psb[b[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(psb[i] >= psa[i]) psb[i] -= psa[i], psa[i] = 0;
            else psa[i] -= psb[i], psb[i] = 0;
        }
        a.clear(), b.clear();
        bool ok = true;
        for(int i=0;i<26;i++){
            if(psb[i]){
                for(int j=0;j<i;j++){
                    if(psa[j]%k){
                        ok = false;
                        break;
                    }
                    psa[j+1] += psa[j];
                    psa[j] = 0;
                }
                if(psb[i] > psa[i]) ok = false;
                psa[i] -= psb[i];
                psb[i] = 0;
            }
            if(!ok) break;
        }
        for(int i=0;i<26;i++)for(int j=0;j<psa[i];j++) a += i + 'a';
        for(int i=0;i<26;i++)for(int j=0;j<psb[i];j++) b += i + 'a';
        if(!ok) cout << "No" << "\n";
        else{
            if(!a.size() and !b.size()) cout << "Yes\n";
            else cout << "No\n";
        }
        
    }
    return 0;
}