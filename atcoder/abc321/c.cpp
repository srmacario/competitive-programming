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

int num[10][100];
void calc(int n){
    num[0][0] = num[0][1] = 1;
    int sum = 0;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 9; j++){
            for(int k = 0; k < j; k++){
                num[j][i] += num[k][i - 1];
            }
            if(sum + num[j][i] >= n){
                cout << j;
                n -= sum;
                for(int d = i - 1; d > 0; d--){
                    int sum = 0;
                    for(int d2 = 0; d2 <= 9; d2++){
                        if(sum + num[d2][d] >= n){
                            cout << d2;
                            n -= sum;
                            break;
                        }
                        sum += num[d2][d];
                    }
                }
                return;
            }
            sum += num[j][i];
            // cout << num[j][i] << " ";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if(n < 10){
        cout << n << "\n";
        return 0;
    }
    calc(n);
    cout << "\n";
    return 0;
}