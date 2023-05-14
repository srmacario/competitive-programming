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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3ff3, MOD = 1e9+7;
const int N = 1e5+5;

int t, k;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> s >> k;
        ll cnt = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            ll aux = 1;
            if (isdigit(s[i])) {
                aux = 0;
                while (isdigit(s[i])) {
                    aux = aux * 10 + (s[i] - '0');
                    if (aux > k) break;
                    i++;
                }
            }

            cnt += aux;
            if (cnt > k) break;
        }
        if (cnt > k) {
            cout << "unfeasible\n";
        } else {
            for (int i = 0; i < (int)s.size(); i++) {
                ll aux = 1;
                if (isdigit(s[i])) {
                    aux = 0;
                    while (isdigit(s[i])) {
                        aux = aux * 10 + (s[i] - '0');
                        i++;
                     }
                }

                while (aux--) {
                    cout << s[i];
                }
            }
            cout << "\n";
        }
    }
    return 0;
}