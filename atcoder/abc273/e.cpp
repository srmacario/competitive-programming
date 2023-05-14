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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    int version = 0;
    int a = 0;
    map<int, pii> seq;
    map<int, int> note;
    for(int i = 1; i <= q; i++){
        string ins;
        cin >> ins;
        if(ins == "ADD"){
            int x;
            cin >> x;
            version++;
            seq[version] = {x, a};
            a = version;
        }
        if(ins == "DELETE"){
            if(a) a = seq[a].nd;
        }
        if(ins == "SAVE"){
            int y;
            cin >> y;
            note.erase(y);
            if(a) note[y] = a;
        }
        if(ins == "LOAD"){
            int z;
            cin >> z;
            if(!note.count(z)) a = 0;
            else a = note[z];
        }
        if(a){
            cout << seq[a].st << " ";
        }
        else{
            cout << "-1 ";
        }
    }
    cout << "\n";
    return 0;
}