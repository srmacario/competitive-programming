#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n, cnt = 0, pos1 = 0, pos2 = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    string a = "aaaaa", b = "aaaaa";
    pos2 = 0;
    while(cnt < n){
        int cycle = 0;
        while(cnt < n and cycle <= 125){
            cout << a + b << "\n";
            cnt++, cycle++;
            if(cycle <= 125){
                b[pos2] = ((b[pos2] - 'a' + 1) % 26) + 'a';
                pos2 = (pos2 + 1) % 5;
            }
        }
        a[pos1] = ((a[pos1] - 'a' + 1) % 26) + 'a';
        pos1 = (pos1 + 1) % 5;
        if(cnt < n) cout << a + b << "\n";
        cnt++; 
        a[pos1] = ((a[pos1] - 'a' + 1) % 26) + 'a';
        pos1 = (pos1 + 1) % 5;
    }
    //db(cnt);
    return 0;
}