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
const int N = 200005;

using namespace std;

int a[N];
int sz[N],sum[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,ans = INF;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        int cont = 0;
        while(a[i]){
            if(sz[a[i]] >= k) break;
            sum[a[i]] += cont;
            sz[a[i]]++;
            a[i]/=2;
            cont++;
        }
        if(sz[a[i]] < k) sum[a[i]] += cont, sz[a[i]]++;
    }
    for(int i=0;i<=N;i++){
        if(sz[i]<k) continue;
        ans = min(ans,sum[i]);
    }
    cout << ans << "\n";
    return 0;
}