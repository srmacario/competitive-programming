#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<int,pii>piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector <int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;
int n;
long double a;
ll x[110],y[110];
    
ll area(int i, int j, int k){
    return abs(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-x[j]*y[i]-x[k]*y[j]-x[i]*y[k]);
}
    
long double st(){
    ll r;
    r=area(n-1,0,1)+area(n-2,n-1,0);
    for(int i=1;i<n-1;i++) r+=area(i-1,i,i+1);
    return abs(r);
}
    
long double sT(){
    ll r=x[n-1]*y[0]-x[0]*y[n-1];
    for(int i=0;i<n-1;i++) r+=x[i]*y[i+1]-x[i+1]*y[i];
    return abs(r);
}
    
int main(){
    scanf("%Lf %d", &a, &n);
    a=1-a;
    for(int i=0;i<n;i++) scanf("%lld %lld", &x[i], &y[i]);
    printf("%0.5Lf\n", sqrt(st()/(a*sT())));
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
int n;
long double a;
long long x[110],y[110];

long long area(int i, int j, int k){
    return abs(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-x[j]*y[i]-x[k]*y[j]-x[i]*y[k]);
}

long double st(){
    long long r;
    r=area(n-1,0,1)+area(n-2,n-1,0);
    for(int i=1;i<n-1;i++) r+=area(i-1,i,i+1);
    return abs(r);
}

long double sT(){
    long long r=x[n-1]*y[0]-x[0]*y[n-1];
    for(int i=0;i<n-1;i++) r+=x[i]*y[i+1]-x[i+1]*y[i];
    return abs(r);
}

int main(){
    scanf("%Lf %d", &a, &n);
    a=1-a;
    for(int i=0;i<n;i++) scanf("%lld %lld", &x[i], &y[i]);
    printf("%0.5Lf\n", sqrt(st()/(a*sT())));
    return 0;
}