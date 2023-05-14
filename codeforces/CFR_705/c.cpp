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
const int N = 1e5+5, M = 26;

int n, k, a[M];
char s[N];

int check(){
    int left = 0;
    for(int i = 0;i < 26; i++){
        int now = a[i]%k;
        // db(i _ now);
        if(now) left += k - now;
    }
    return left;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%s", &n, &k, s);
        for(int i = 0; i < 26; i++) a[i] = 0;
        if(n%k){
            printf("-1\n");
            continue;
        }
        for(int i = 0; i < n; i++){
            a[s[i] - 'a']++;
        }
        int ok = check();
        if(!check()){
            printf("%s\n", s);
            continue;
        }
        if(ok){
            for(int i = n-1; i >= 0; i--){
                a[s[i] - 'a']--;
                for(int j = s[i] - 'a' + 1; j < 26; j++){
                    a[j]++;
                    int cur = check();
                    // db(cur);
                    if(n-1-i >= cur and !((n-1-i - cur)%k)){
                        // db(cur _ i _ j);
                        s[i] = j+'a';
                        for(int x = 0; x < i+1; x++) printf("%c", s[x]);
                        for(int x = 0; x < n-i-1-cur; x++) printf("a");
                        for(int x = 0; x < 26; x++){
                            char c = x + 'a';
                            while(a[x]%k){
                                printf("%c", c);
                                a[x]++;
                            }
                        }
                        printf("\n");
                        ok = 0;
                        break;
                    }
                    a[j]--;
                }
                if(!ok) break;
            }
        }
        if(ok){
            for(int i = 0; i < n; i++) printf("z");
            printf("\n");
        }
    }
    return 0;
}