#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

int a[N];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    long long ans = 0;
    for(int i=1;i<n;i++) ans += max(0,a[i-1]-a[i]), a[i] += max(0,a[i-1]-a[i]);
    cout << ans << "\n";
    return 0;
}