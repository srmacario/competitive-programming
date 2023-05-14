#include <bits/stdc++.h>
using namespace std;

int a[3], sum, ans;

int main(){
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    sum = a[0] + a[1] + a[2];
    ans = sum - 100 * ((a[0] >= 500) + (a[1] >= 500) + (a[2] >= 500));
    ans = min(ans, sum - 100 * ((a[0] >= 500) + (a[1] + a[2] >= 500)));
    ans = min(ans, sum - 100 * ((a[1] >= 500) + (a[0] + a[2] >= 500)));
    ans = min(ans, sum - 100 * ((a[2] >= 500) + (a[1] + a[0] >= 500)));
    ans = min(ans, sum - 100 * ((a[0] + a[1] + a[2] >= 500)));
    printf("%d\n", ans);
    return 0;
}