#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5 + 5;

int n, k, a[N];
map<int, int> freq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < k; i++){
        freq.clear();
        for(int j = 0; j < n; j++){
            freq[a[j]]++;
        }
        bool ok = true;
        for(int j = 0; j < n; j++){
            ok &= (a[j] == freq[a[j]]);
            a[j] = freq[a[j]];
        }
        if(ok) break;
    }
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
    return 0;
}