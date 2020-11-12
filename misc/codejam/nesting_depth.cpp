#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int k=1;k<=t;k++){
        string s, r;
        cin >> s;
        for(int i=0;i<s.size();i++){
            if(!i){
                for(int j=0;j<(s[i]-'0');j++) r+='(';
                r+=s[i];
            }
            else{
                if(s[i] > s[i-1]){
                    for(int j=0;j<(s[i]-s[i-1]);j++) r+='(';
                    r+=s[i];
                }
                else if(s[i] < s[i-1]){
                    for(int j=0;j<(s[i-1]-s[i]);j++) r+=')';
                    r+=s[i];
                }
                else r+=s[i];
            }
        }
        for(int j=0;j<(s[s.size()-1]-'0');j++) r+=')';
        cout << "Case #" << k << ": " << r << "\n";
    }
    return 0;
}