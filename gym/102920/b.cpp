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

int a[10], b[10];


int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main(){
    for(int i = 0; i < 6; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < 6; i++){
        scanf("%d", &b[i]);
    }
    int num = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(b[j] < a[i]) num++;
        }
    }
    printf("%d/%d\n", num/gcd(num,36), 36/(gcd(num,36)));
    return 0;
}