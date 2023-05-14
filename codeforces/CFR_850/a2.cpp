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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int c[2][2] = {0}, cnt = 0;
        c[0][0] += 1;
        cnt++;
        n -= 1;
        int p = 1;
        for(int i = 2; n; i++){
            if(n - i > 0){
                n -= i;
                c[p][0] += i/2;
                c[p][1] += i/2;
                //par
                if(cnt % 2){
                    //par
                    if(!((cnt + i) % 2)) c[p][1]++;
                }
                else{
                    if(((cnt + i) % 2)) c[p][0]++;
                }
                cnt += i;
            }
            else{
                c[p][0] += n/2;
                c[p][1] += n/2;
                //par
                if(cnt % 2){
                    //par
                    if(!((cnt + n) % 2)) c[p][1]++;
                }
                else{
                    if(((cnt + n) % 2)) c[p][0]++;
                }
                break;
            }
            i++;
            if(n - i > 0){
                n -= i;
                c[p][0] += i/2;
                c[p][1] += i/2;
                //par
                if(cnt % 2){
                    //par
                    if(!((cnt + i) % 2)) c[p][1]++;
                }
                else{
                    if(((cnt + i) % 2)) c[p][0]++;
                }
                cnt += i;
            }
            else{
                c[p][0] += n/2;
                c[p][1] += n/2;
                //par
                if(cnt % 2){
                    //par
                    if(!((cnt + n) % 2)) c[p][1]++;
                }
                else{
                    if(((cnt + n) % 2)) c[p][0]++;
                }
                break;
            }
            p ^= 1;
        }
        cout << c[0][0] << " " << c[0][1] << " " << c[1][0] << " " << c[1][1] << "\n";
    }
    return 0;
}