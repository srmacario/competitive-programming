#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.);

int main(){
    int n, r;
    scanf("%d%d", &n, &r);
    double ans = r / ((2*sin(PI/2 - PI/n)/sin(2*PI/n)) - 1);
    printf("%.10lf\n", ans);
    return 0;
}