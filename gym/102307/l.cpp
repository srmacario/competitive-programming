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
const int N = 1e6+5, M = 105;

int cmp[N], par[N], id[M];
vi num;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        num.pb(x);
        id[x] = i;
    }
    cmp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<N;j++){
            if(cmp[j]){
                if(num[i]+j <= N){
                    cmp[num[i]+j] = 1;
                    par[num[i]+j] = num[i];
                }
            } 
        }
    }
    num.clear();
    for(int j=0;j<N;j++){
        if(cmp[j]) num.pb(j);
    }
    vi drop(n);
    int l = 0, r = num.size()-1, mid, cur;
    while(l <= r){
        for(int i=0;i<n;i++) drop[i] = 0;
        mid = (l+r)/2;
        cur = num[mid];
        cout << 1 << endl;
        while(par[cur] != cur){
            drop[id[par[cur]]]++;
            cur -= par[cur];
        }
        if(cur) drop[id[cur]]++;
        for(int i=0;i<n;i++) cout << drop[i] << " ";
        string ans;
        cin >> ans;
        if(ans == "yellow"){
            cout << 2 << "\n" << cur << endl;
            return 0;
        }
        else if(ans == "green") l = mid+1;
        else r = mid -1;
    }
    string last;
    for(int i=mid-1;i<=mid+1;i++){
        for(int j=0;j<n;j++) drop[j] = 0;
        cur = num[i];
        cout << 1 << endl;
        while(par[cur] != cur){
            drop[id[par[cur]]]++;
            cur -= par[cur];
        }
        if(cur) drop[id[cur]]++;
        for(int j=0;j<n;j++) cout << drop[j] << " ";
        string ans;
        cin >> ans;
        if(ans == "red" and last == "green"){
            if(num[i] - num[i-1] == 2){
                cout << 2 << "\n" << num[i]-1 << endl;
                return 0;
            }
        }
        last = ans;
    }
    cout << "2\n-1" << endl;
    return 0;
}