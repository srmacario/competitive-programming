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

string s;
int freq[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    if(s.size() > 26){
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    for(int i = 0; i < (int)s.size(); i++){
        freq[s[i] - 'a']++;
    }
    for(int i = 0; i < (int)s.size(); i++){
        if(freq[s[i] - 'a'] > 1){
            for(int j = 0; j < 26; j++){
                if(!freq[j]){
                    freq[s[i] - 'a']--;
                    s[i] = 'a' + j;
                    freq[j]++;
                    break;
                }
            }
        }
    }
    cout << s << "\n";
    return 0;
}