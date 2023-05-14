#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define push_back

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;
const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9  +7;
const int N = 25;

ll n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    if(n > m) swap(n,m);
    for(int i=n+1;i<=m+1;i++){
        cout << i << "\n";
    }
    return 0;
}