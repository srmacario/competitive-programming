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
const int N = 1e6+10;

int m,n,k, cmp[N];
vi pr;
map <ll,int> ans;

void sieve(){
    for(ll i=2;i<N;i++) 
    if(!cmp[i]){
        for(ll j=i*i;j<N;j+=i) cmp[j] = 1;
        pr.pb(i);
    }
}

long long gcd(long long x, long long y){
	long long h;
	if(x<y) swap(x,y);
	while(x%y){
		h=x%y;
		x=y;
		y=h;
	}
	return y;
}

long long mul(long long x, long long y, long long n){
	long long r=0;
	while(y){
		if(y&1) r=(r+x)%n;
		y/=2;
		x=(x+x)%n;
	}
	return r;
}

long long pow(long long x, long long y, long long n){
	long long r=1;
	while(y){
		if(y&1) r=mul(r,x,n);
		y/=2;
		x=mul(x,x,n);
	}
	return r;
}

long long pollard_rho(long long n) {
    long long x,y,d,c=1;
    if(!(n%2)) return 2;
    while(1) {
        y=x=2;
        while(1) {
            x=mul(x,x,n); x=(x+c)%n;
            y=mul(y,y,n); y=(y+c)%n;
            y=mul(y,y,n); y=(y+c)%n; 
            d=gcd(abs(y-x),n);
            if(d==n) break ; 
            else if(d>1) return d; 
        }
        c++;
    }
}

bool miller_rabin(long long a , long long n) {
    if(a>=n) return true;
    long long r=0,s=n-1,j;
    while(!(s & 1)) s>>=1,r++;
    long long x=pow(a,s,n);
    if(x==1) return true;
    for(j=0;j<r;j++,x=mul(x,x,n)) if (x==n-1) return true ;
    return false ;
}
 
bool isprime (long long n) {
    long long base[]={2,3,5,7,11,13,17,19,23,29};
    for(int i=0;i<10;i++) if(!miller_rabin(base[i],n)) return false;
    return true ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> k;
    sieve();
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        for(int j=0;j<pr.size();j++){
            if(x == 1) break;
            if(!(x%pr[j])) ans[pr[j]]++;
            while(!(x%pr[j])){
                x/=pr[j];
            }
        }
        if(x > 1){
            if(isprime(x)) ans[x]++;
            else{
                ll f = pollard_rho(x);
                ans[f]++, ans[x/f]++;
            }
        }
    }
    for(int i=0;i<k;i++){
        int a,b,c;
        cin >> a >> b >> c;
    }
    for(auto u:ans){
        cout << u.st << " ";
    }
    cout << "\n";
    return 0;
}