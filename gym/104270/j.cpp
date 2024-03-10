#include <bits/stdc++.h>

using namespace std;

#define nd second
#define st first
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<


typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a;
        ll sum = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(!x) cnt++;
            else a.push_back(x);
        }
        int cur = 0, mn = INF;
        for(int i = 0; i < a.size(); i++){
            if((cnt + cur) < m){
                sum += a[i];
                cur++;
                continue;
            }
            if(cnt + cur == m){
                mn = min(mn, a[i]);
            }
        }
        bool ok = false;
        if(cur + cnt == m) ok = true;
        if(!ok) cout << "Impossible\n";
        else{
            if(mn == INF) cout << "Richman\n";
            else cout << (sum + mn - 1) << "\n";
        }
    }

    return 0;
}