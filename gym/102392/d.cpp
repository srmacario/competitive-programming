#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size() / 2;
    map<char, int> cnt;
    set<char> gn;
    for(int i = 0; i < 2 * n; i++){
        if(++cnt[s[i]] == n) gn.insert(s[i]);
    }
    sort(s.begin(), s.end());
    if(gn.size() == 0 or gn.size() == 2){
        cout << "YES\n" << s << "\n";   
    }
    else{
        char big = *gn.begin();
        if(cnt[big] == n){
            cout << "YES\n" << s << "\n";   
        }
        else if(cnt[big] == 2 * n){
            cout << "NO\n";
        }
        else if(cnt[big] == 2 * n - 1){
            if(n == 1) cout << "YES\n" << s << "\n";
            else cout << "NO\n";
        }
        else if(cnt[big] == 2 * n - 2){
            if(cnt.size() == 2){
                if(n <= 2) cout << "YES\n" << s << "\n";
                else cout << "NO\n";
            }
            else{
                cout << "YES\n";
                for(auto u : cnt){
                    if(u.st == big) continue;
                    
                    cout << u.st;
                    for(int i = 1; i <= n - 1; i++) cout << big;
                }
                cout << "\n";
            }
        }
        else{
            cout << "YES\n";
            for(auto u : cnt){
                if(u.st == big) continue;

                cout << u.st;
                cnt[u.st]--;
                for(int i = 1; i <= n; i++) cout << big;
                cnt[big] -= n;
                break;
            }
            for(auto u : cnt){
                if(u.st == big) continue;

                for(int i = 1; i <= u.nd; i++) cout << u.st;
            }
            for(int i = 1; i <= cnt[big]; i++) cout << big;
            cout << "\n";
        }
    }
}