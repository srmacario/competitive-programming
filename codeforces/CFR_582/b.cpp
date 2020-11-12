#include <bits/stdc++.h>
#define ll long long
#define st first
#define nd second
#define pb push_back
#define pii pair <int, int>
#define triplet <pair <pii,int>>
#define vi vector<int>
#define vii vector<vi>
#define clr(x) x.clear()
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, ans=0, k;
        vi a;
        cin >> n;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            a.pb(x);
        }
        k = a[n-1];
        for(int i=n-2;i>=0;i--){
            if(a[i]>k) ans++;
            k = min(k,a[i]);
        }
        cout << ans << "\n";
    }


    return 0;
}