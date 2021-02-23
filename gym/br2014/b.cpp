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

char s[N];

int main(){
    int a,b;
    scanf("%d%d%s",&a,&b,s);
    int n = strlen(s);
    int lw=-1, rw=-1, lb=-1, rb=-1;
    for(int i=0;i<n;i++){
        if(s[i] == 'W'){
            if(lw == -1) lw = i;
            rw = i;
        }
        if(s[i] == 'B'){
            if(lb == -1 and lw != -1) lb = i;
            rb = i;
        }
    }
    int ans = 0;
    while(true){
        if((lb-lw)*(a-b) <= a){
            ans += (lb-lw)*(a-b);
            lw++;
        }
        else{

        }
    }
    return 0;
}