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

int t, n;
string d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        //declaration
        deque<int> bnum,snum;
        vector <pair<char,int>> left;
        cin >> n >> d;
        vi blis,slis;
        //initialize number vectors
        for(int i=0;i<=n;i++) blis.pb(0), slis.pb(0);
        for(int i=1;i<=n;i++){
            bnum.pb(i), snum.pb(i);
        }
        //find the "first" <, to calculate smaller lis
        int cnt = 1;
        for(int i=0;i<n-1;i++){
            if(d[i] == '<' and cnt == 1) left.pb({d[i],i}), cnt++;
            else if(d[i] == '>') cnt = 1;
        }
        //calculate greater lis
        for(int i=0;i<n-1;i++){
            if(d[i] == '<') blis[i+1] = bnum.front(), bnum.pop_front();
        }
        for(int i=n;i>=1;i--){
            if(!blis[i]) blis[i] = bnum.front(),bnum.pop_front();
        }

        //calculate smaller lis
        for(int i=left.size()-1;i>=0;i--){
            int j = left[i].nd;
            while(d[j] == '<'){
                slis[j+1] = snum.front(), snum.pop_front();
                j++;
            }
        }
        for(int i=n;i>=1;i--){
            if(!slis[i]) slis[i] = snum.front(),snum.pop_front();
        }
        //print
        for(int i=1;i<=n;i++) cout << slis[i] << " ";
        cout << "\n";
        for(int i=1;i<=n;i++) cout << blis[i] << " ";
        cout << "\n";
    }
    return 0;
}