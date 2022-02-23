#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e3 + 5;

bool b[N], b1[N], b2[N];
vector<int> s[2];

void print() {
    cout << "printing stack 1\n";
    for (auto x : s[0]) cout << x << " ";
    cout << "\n";
    cout << "printing stack 2\n";
    for (auto x : s[1]) cout << x << " ";
    cout << "\n";
}

int main() {
    int n, a, nxt = 1;
    scanf("%d", &n);
    while(nxt <= n){
        if(!b[nxt]){
            scanf("%d", &a);
            printf("1\n");
            s[0].push_back(a);
            b1[a] = true;
            b[a] = true;
        }
        if(b1[nxt]){
            while(s[0].back() != nxt){
                printf("12\n");
                s[1].push_back(s[0].back());
                b2[s[0].back()] = true;
                b1[s[0].back()] = false;
                s[0].pop_back();
            }
            printf("-1\n");
            nxt++;
            s[0].pop_back();
        }
        if(b2[nxt]){
            while(s[1].back() != nxt){
                printf("21\n");
                s[0].push_back(s[1].back());
                b1[s[1].back()] = true;
                b2[s[1].back()] = false;
                s[1].pop_back();
            }
            printf("-2\n");
            nxt++;
            s[1].pop_back();
        }
    }
    return 0;
}