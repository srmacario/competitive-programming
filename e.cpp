#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string, int> hours[2];
    vector<string> names;
    int shift = 0;
    while(true){
        string s;
        cin >> s;
        if(s == "======") break;
        if(s == "------"){
            shift++;
            continue;
        }
        int e;
        string n;
        cin >> e >> n;
        int is = stoi(s);
        hours[shift][n] += (e - is);
        names.push_back(n);
    }
    sort(names.begin(), names.end());
    names.resize(unique(names.begin(), names.end()) - names.begin());
    bool ok = false;
    for(auto n : names){
        int dif = hours[1][n] - hours[0][n];
        if(dif == 0) continue;
        if(dif > 0) cout << n << " +" << dif << "\n";
        if(dif < 0) cout << n << " " << dif << "\n";
        ok = true;
    }
    if(!ok) cout << "No differences found.\n";
    return 0;
}