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

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int a[5], p[5] = {0}, k;
        cin >> a[0] >> a[1] >> k;
        a[4] = gcd(a[0], a[1]);
        a[2] = a[0]/a[4];
        a[3] = a[1]/a[4];
        for(int i = 0; i < 2; i++){
            for(int j = 2; j*j <= a[i]; j++){
                while(!(a[i]%j)){
                    a[i]/=j;
                    p[i]++;
                }
            }
            if(a[i] > 1) p[i]++;
        }
        if(k <= p[0] + p[1] and k >= 2){
            printf("YES\n");
        }
        else if(k == 1){
            if((a[2] != a[3]) and (min(a[2],a[3]) == 1)) printf("YES\n");
            else printf("NO\n");
        }
        else printf("NO\n");
    }
    return 0;
}