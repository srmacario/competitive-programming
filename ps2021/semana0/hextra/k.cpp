#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5+5;
 
int a[N];
 
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    long long ans = 0;
    for(int i=1;i<n;i++) ans += max(0,a[i-1]-a[i]), a[i] += max(0,a[i-1]-a[i]);
    printf("%lld\n", ans);
    return 0;
}