#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5 + 5;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int i = 0, j = 0, ans = 0;
    while(i < n and j < n){
        string resp;

        cout << "? " << i << " " << j + 1 << endl;
        cin >> resp;
        if(resp == "absent"){
            i = j + 1;
            j = i;
            ans++;
        }
        else{
            j++;
        }
    }
    cout << "! " << ans << endl;
    return 0;
}