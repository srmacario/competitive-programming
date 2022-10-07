#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, a[N], k;
long long sum;

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for(int i = 0; i < k; i++)
        sum += a[n - i - 1];
    printf("%lld\n", sum);
    return 0;
}