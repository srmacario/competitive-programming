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

ll n, d, p, tmp;
vector<pll> eyes;

//sort by difference of total and lower bound
bool cmp(pll a, pll b){
    return (a.nd - a.st + 1) < (b.nd - b.st + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    eyes.resize(n);
    for(int i = 0; i < n; i++){
        cin >> eyes[i].nd >> eyes[i].st;
    }
    //calculating answer in case all b > 0
    //in this case, the last group will kill themselves at the next day
    sort(eyes.begin(), eyes.end(), cmp);
    if(n > 1) tmp = min(eyes[eyes.size() - 1].nd - eyes[eyes.size() - 1].st + 1, eyes[eyes.size() - 2].nd  - eyes[eyes.size() - 2].st + 2);
    
    //calculating answer in case some b is 0
    //answer will be the maximum difference of days, excluding the b = 0 ones
    sort(eyes.begin(), eyes.end());
    while(!eyes.empty()){
        if(eyes.back().st > 0) d = max(d, eyes.back().nd - eyes.back().st + 1ll), p += eyes.back().nd;
        else break;
        eyes.pop_back();
    }

    //if there is only one of b = 0 kind, they die in the next day
    if(eyes.size() == 1) d++, p += eyes.back().nd;
    else if(eyes.size() == 0) d = tmp;
    cout << d << " " << p << "\n";
    return 0;
}