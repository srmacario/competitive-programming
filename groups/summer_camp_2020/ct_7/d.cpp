#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ld e = 0,g = 0, aux = 0;
    ld a1,b1,a2,b2;
    cin >> a1 >> b1 >> a2 >> b2;
    for(int i=a1;i<=b1;i++){
        g += i;
    }
    g /= (b1-a1+1);
    for(int i=a2;i<=b2;i++){
        aux += i;
    }
    aux /= (b2-a2+1);
    g+=aux, aux = 0;
    cin >> a1 >> b1 >> a2 >> b2;
    for(int i=a1;i<=b1;i++){
        e += i;
    }
    e /= (b1-a1+1);
    for(int i=a2;i<=b2;i++){
        aux += i;
    }
    aux /= (b2-a2+1);
    e+=aux, aux = 0;
    if(e>g) cout << "Emma\n";
    else if(e<g) cout << "Gunnar\n";
    else cout << "Tie\n";
    return 0;
}