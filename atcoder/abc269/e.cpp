#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    pair<pii, pii> cur = {{1, n}, {1, n}};
    //find line
    while(cur.st.nd > cur.st.st){
        int t;
        int mid = (cur.st.nd + cur.st.st) / 2;

        int hooks_left = mid - cur.st.st + 1;
        // int hooks_right = cur.st.nd - mid + 1;

        cout << "? " << cur.st.st << " " << mid << " " << 1 << " " << n << endl;
        cin >> t;
        if(t == hooks_left) cur.st.st = mid + 1;
        else cur.st.nd = mid;
    }

    //find column
    while(cur.nd.nd > cur.nd.st){
        int t;
        int mid = (cur.nd.nd + cur.nd.st)/2;

        int hooks_left = mid - cur.nd.st + 1;
        // int hooks_right = cur.nd.nd - mid + 1;

        cout << "? " << 1 << " " << n << " " << cur.nd.st << " " << mid << endl;
        cin >> t;

        if(t == hooks_left) cur.nd.st = mid + 1;
        else cur.nd.nd = mid;
    }
    cout << "! " << cur.st.st << " " << cur.nd.st << "\n";
    return 0;
}
/*
    (1, n/2) (1, n) -> (1, n/2) (1, n/2) | (1, n/2) (n/2 + 1, n)

*/
/*
    ...
    ...
    ...

    ...
    ...

*/